#include "x2tTester.h"
#include "../../../X2tConverter/src/run.h"

struct FormatsList;
class Cx2tTester;
class CConverter;

FormatsList::FormatsList()
{
}

bool FormatsList::isDocoment(int format)
{
	return std::find(documents.begin(), documents.end(), format) != documents.end();
}
bool FormatsList::isPresentation(int format)
{
	return std::find(presentations.begin(), presentations.end(), format) != presentations.end();
}
bool FormatsList::isSpreadsheet(int format)
{
	return std::find(spreadsheets.begin(), spreadsheets.end(), format) != spreadsheets.end();
}
bool FormatsList::isCrossplatform(int format)
{
	return std::find(crossplatform.begin(), crossplatform.end(), format) != crossplatform.end();
}
bool FormatsList::isImage(int format)
{
	return std::find(images.begin(), images.end(), format) != images.end();
}

void FormatsList::SetDefault()
{
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_RTF);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_TXT);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_HTML);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MHT);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_EPUB);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_FB2);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MOBI);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCM);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTX);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTM);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT_FLAT);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OTT);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OFORM);
	documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCXF);

	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPT);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSX);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSM);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTX);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTM);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP_FLAT);
	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_OTP);

	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLS);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_CSV);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSM);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLTM);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSB);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS_FLAT);
	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_OTS);

	crossplatform.push_back(AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_PDF);

	images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_JPG);
	images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_PNG);
}


Cx2tTester::Cx2tTester(const std::wstring& configPath)
{
	m_bIsUseSystemFonts = true;
	setConfig(configPath);

	if(NSFile::CFileBinary::Exists(m_reportFile))
		NSFile::CFileBinary::Remove(m_reportFile);

	if(!m_reportStream.CreateFileW(m_reportFile))
	{
		std::wcerr << "Report file is not open!" << std::endl;
		exit(-1);
	}


	m_coresCS.InitializeCriticalSection();
	m_reportCS.InitializeCriticalSection();
	m_outputCS.InitializeCriticalSection();

	m_currentProc = 0;
	setReportHeader();
}
Cx2tTester::~Cx2tTester()
{
	m_coresCS.DeleteCriticalSection();
	m_reportCS.DeleteCriticalSection();
	m_outputCS.DeleteCriticalSection();

	m_reportStream.CloseFile();
}

void Cx2tTester::setConfig(const std::wstring& configPath)
{
	XmlUtils::CXmlNode root;
	XmlUtils::CXmlNodes nodes;
	if(root.FromXmlFile(configPath) && root.GetChilds(nodes))
	{
		for(int i = 0; i < nodes.GetCount(); i++)
		{
			XmlUtils::CXmlNode node;
			nodes.GetAt(i, node);
			std::wstring name = node.GetName();

			// key-value
			if(name == L"reportPath") m_reportFile = node.GetText();
			else if(name == L"inputDirectory") m_inputDirectory = node.GetText();
			else if(name == L"outputDirectory") m_outputDirectory = node.GetText();
			else if(name == L"x2tPath") m_x2tPath = node.GetText();
			else if(name == L"cores") m_maxProc = std::stoi(node.GetText());
			else if (name == L"fonts")
			{
				m_bIsUseSystemFonts = (1 == node.ReadValueInt(L"system", 1)) ? true : false;
				XmlUtils::CXmlNodes oNodeFontDirs = node.ReadNodesNoNS(L"directories");
				for (int nIndex = 0, nCount = oNodeFontDirs.GetCount(); nIndex < nCount; ++nIndex)
				{
					XmlUtils::CXmlNode oNodeDir;
					oNodeFontDirs.GetAt(nIndex, oNodeDir);
					m_arAdditionalFontsDirs.push_back(oNodeDir.GetText());
				}
			}
		}
	}
	// else err
}
void Cx2tTester::Start()
{
	// check fonts
	std::wstring fonts_directory = NSFile::GetProcessDirectory() + L"/fonts";
	CApplicationFontsWorker fonts_worker;
	fonts_worker.m_sDirectory = fonts_directory;
	if (!NSDirectory::Exists(fonts_worker.m_sDirectory))
		NSDirectory::CreateDirectory(fonts_worker.m_sDirectory);

	fonts_worker.m_bIsUseSystemFonts = m_bIsUseSystemFonts;

	for (std::vector<std::wstring>::iterator i = m_arAdditionalFontsDirs.begin(); i != m_arAdditionalFontsDirs.end(); i++)
		fonts_worker.m_arAdditionalFolders.push_back(*i);

	fonts_worker.m_bIsNeedThumbnails = false;
	NSFonts::IApplicationFonts* pFonts = fonts_worker.Check();
	RELEASEINTERFACE(pFonts);

	// setup & clear output folder
	if(NSDirectory::Exists(m_outputDirectory))
		NSDirectory::DeleteDirectory(m_outputDirectory);

	NSDirectory::CreateDirectory(m_outputDirectory);

	std::vector<std::wstring> files = NSDirectory::GetFiles(m_inputDirectory, false);
	FormatsList formats_list;
	formats_list.SetDefault();

	if(files.size() < m_maxProc)
		m_maxProc = files.size();

	for(std::wstring& input_file : files)
	{
		// setup folder for output files
		std::wstring output_files_directory = m_outputDirectory + L'/' + NSFile::GetFileName(input_file);

		if(NSDirectory::Exists(output_files_directory))
			NSDirectory::DeleteDirectory(output_files_directory);

		NSDirectory::CreateDirectory(output_files_directory);

		std::wstring input_ext = NSFile::GetFileExtention(input_file);
		int input_format = COfficeFileFormatChecker::GetFormatByExtension(L'.' + input_ext);

		// setup output_formats
		std::vector<int> output_formats;

		if(formats_list.isDocoment(input_format))
			output_formats = formats_list.documents;

		if(formats_list.isPresentation(input_format))
			output_formats = formats_list.presentations;

		if(formats_list.isSpreadsheet(input_format))
			output_formats = formats_list.spreadsheets;

		for(auto it : formats_list.crossplatform)
			output_formats.push_back(it);

		for(auto it : formats_list.images)
			output_formats.push_back(it);

		// waiting...
		while(isAllBusy())
			Sleep(100);

		// setup & start new coverter
		m_currentProc++;
		CConverter *converter = new CConverter(this);
		converter->SetInputFile(input_file);
		converter->SetInputFormat(input_format);
		converter->SetOutputFilesDirectory(output_files_directory);
		converter->SetOutputFormats(output_formats);
		converter->SetFontsDirectory(fonts_directory);
		converter->SetX2tPath(m_x2tPath);

		converter->DestroyOnFinish();
		converter->Start(0);
	}

	// waiting all procs end
	while(!isAllFree())
		Sleep(100);
}

void Cx2tTester::writeReport(const Report& report)
{
	CTemporaryCS CS(&m_reportCS);

	m_reportStream.WriteStringUTF8(report.inputFile + L"\t", true);
	m_reportStream.WriteStringUTF8(report.outputFile + L"\t", true);
	m_reportStream.WriteStringUTF8(report.inputExt + L"\t", true);
	m_reportStream.WriteStringUTF8(report.outputExt + L"\t", true);
	m_reportStream.WriteStringUTF8(std::to_wstring(report.exitCode) + L"\n", true);
}
void Cx2tTester::writeReports(const std::vector<Report>& reports)
{
	CTemporaryCS CS(&m_reportCS);
	for(auto& report : reports)
	{
		m_reportStream.WriteStringUTF8(report.inputFile + L"\t", true);
		m_reportStream.WriteStringUTF8(report.outputFile + L"\t", true);
		m_reportStream.WriteStringUTF8(report.inputExt + L"\t", true);
		m_reportStream.WriteStringUTF8(report.outputExt + L"\t", true);
		m_reportStream.WriteStringUTF8(std::to_wstring(report.exitCode) + L"\n", true);
	}
}

bool Cx2tTester::isAllBusy()
{
	CTemporaryCS CS(&m_coresCS);
	return m_currentProc == m_maxProc;
}
bool Cx2tTester::isAllFree()
{
	CTemporaryCS CS(&m_coresCS);
	return m_currentProc == 0;
}

void Cx2tTester::setReportHeader()
{
	m_reportStream.WriteStringUTF8(L"Input file\t", false);
	m_reportStream.WriteStringUTF8(L"Output file\t", true);
	m_reportStream.WriteStringUTF8(L"Input extension\t", true);
	m_reportStream.WriteStringUTF8(L"Output extension\t", true);
	m_reportStream.WriteStringUTF8(L"Exit code\n", true);
}


CConverter::CConverter(Cx2tTester* internal) : m_internal(internal)
{
}
CConverter::~CConverter()
{
	Stop();
}

void CConverter::SetInputFile(const std::wstring& inputFile)
{
	m_inputFile = inputFile;
}
void CConverter::SetInputFormat(int inputFormat)
{
	m_inputFormat = inputFormat;
}

void CConverter::SetOutputFilesDirectory(const std::wstring& outputFilesDirectory)
{
	m_outputFilesDirectory = outputFilesDirectory;
}
void CConverter::SetOutputFormats(const std::vector<int> outputFormats)
{
	m_outputFormats = outputFormats;
}

void CConverter::SetFontsDirectory(const std::wstring& fontsDirectory)
{
	m_fontsDirectory = fontsDirectory;
}
void CConverter::SetX2tPath(const std::wstring& x2tPath)
{
	m_x2tPath = x2tPath;
}

DWORD CConverter::ThreadProc()
{
	std::wstring xml_params_file = m_outputFilesDirectory + L"/params.xml";
	std::vector<Cx2tTester::Report> reports;

	// input_format in many output exts
	for(int& output_format : m_outputFormats)
	{
		if(m_inputFormat == output_format)
			continue;

		std::wstring output_file = m_outputFilesDirectory
				+ L"/" + NSFile::GetFileName(m_inputFile) + checker.GetExtensionByType(output_format);

		// creating temporary xml file with params
		NSStringUtils::CStringBuilder builder;
		builder.WriteString(L"<?xml version=\"1.0\" encoding=\"utf-8\"?>");

		builder.WriteString(L"<Root>");

		builder.WriteString(L"<m_sFileFrom>");
		builder.WriteEncodeXmlString(m_inputFile);
		builder.WriteString(L"</m_sFileFrom>");

		builder.WriteString(L"<m_sFileTo>");
		builder.WriteEncodeXmlString(output_file);
		builder.WriteString(L"</m_sFileTo>");

		builder.WriteString(L"<m_nFormatFrom>");
		builder.WriteString(std::to_wstring(m_inputFormat));
		builder.WriteString(L"</m_nFormatFrom>");

		builder.WriteString(L"<m_nFormatTo>");
		builder.WriteString(std::to_wstring(output_format));
		builder.WriteString(L"</m_nFormatTo>");

		builder.WriteString(L"<m_sThemeDir>./</m_sThemeDir>");
		builder.WriteString(L"<m_bDontSaveAdditional>true</m_bDontSaveAdditional>");

		builder.WriteString(L"<m_sAllFontsPath>");
		builder.WriteEncodeXmlString(m_fontsDirectory + L"/AllFonts.js");
		builder.WriteString(L"</m_sAllFontsPath>");

		builder.WriteString(L"<m_sFontDir>");
		builder.WriteEncodeXmlString(m_fontsDirectory);
		builder.WriteString(L"</m_sFontDir>");

		builder.WriteString(L"<m_oThumbnail><format>4</format><aspect>2</aspect><first>false</first><width>1000</width><height>1000</height></m_oThumbnail>");
		builder.WriteString(L"<m_sJsonParams>{&quot;spreadsheetLayout&quot;:{&quot;gridLines&quot;:true,&quot;headings&quot;:true,&quot;fitToHeight&quot;:1,&quot;fitToWidth&quot;:1,&quot;orientation&quot;:&quot;landscape&quot;}}</m_sJsonParams>");

		builder.WriteString(L"</Root>");

		std::wstring xml_params = builder.GetData();

		NSFile::CFileBinary::SaveToFile(xml_params_file, xml_params, true);

		int exit_code = NSX2T::Convert(NSFile::GetDirectoryName(m_x2tPath), xml_params_file);

		// writing report
		Cx2tTester::Report report;
		report.inputFile = m_inputFile;
		report.outputFile = output_file;
		report.inputExt = checker.GetExtensionByType(m_inputFormat);
		report.outputExt = checker.GetExtensionByType(output_format);
		report.exitCode = exit_code;
		reports.push_back(report);

		std::string input_file_UTF8 = U_TO_UTF8(m_inputFile);
		std::string output_file_UTF8 = U_TO_UTF8(output_file);

		CTemporaryCS CS(&m_internal->m_outputCS);
		if(!exit_code)
			std::cout << input_file_UTF8 << " to " << output_file_UTF8 << " " << "OK" << std::endl;
		else
			std::cout << input_file_UTF8  << " to " << output_file_UTF8 << " " << "BAD" << std::endl;

	}
	NSFile::CFileBinary::Remove(xml_params_file);
	m_internal->writeReports(reports);
	m_internal->m_currentProc--;
	return 0;
}


