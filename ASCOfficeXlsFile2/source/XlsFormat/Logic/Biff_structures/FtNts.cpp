#include "precompiled_xls.h"
#include "FtNts.h"
#include <Binary/CFRecord.h>
//#include <Exception/AttributeDataWrong.h>

namespace XLS
{;


BiffStructurePtr FtNts::clone()
{
	return BiffStructurePtr(new FtNts(*this));
}


//void FtNts::setXMLAttributes(MSXML2::IXMLDOMElementPtr own_tag)
//{
//	own_tag->setAttribute(L"guid", guid);
//	own_tag->setAttribute(L"fSharedNote", fSharedNote);
//}
//
//
//void FtNts::getXMLAttributes(MSXML2::IXMLDOMElementPtr own_tag)
//{
//	guid = getStructAttribute(own_tag, L"guid");
//	fSharedNote = static_cast<bool>(getStructAttribute(own_tag, L"fSharedNote"));
//}


void FtNts::store(CFRecord& record)
{
	unsigned __int16 ft = 0x0D; // reserved
	unsigned __int16 cb = 0x16; // reserved
	record << ft << cb;

	GUID guid_num;
	if(!STR::bstr2guid(guid, guid_num))
	{
		throw;// EXCEPT::LE::AttributeDataWrong(L"guid", L"FtNts", guid);
	}
	record << guid_num << fSharedNote;
}


void FtNts::load(CFRecord& record)
{
	record.skipNunBytes(4); // reserved

	GUID guid_num;
	record >> guid_num >> fSharedNote;
	guid = STR::guid2bstr(guid_num);
	record.skipNunBytes(4);
}


} // namespace XLS
