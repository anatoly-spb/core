
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include "xlsx_drawing_context.h"

#include <simple_xml_writer.h>
#include <utils.h>

namespace oox {


class xlsx_drawing_context_handle::Impl
{
public:
    Impl(external_items & items)
        : items_(items), next_rId_(1), next_drawing_id_(1) 
    {
    }  

    external_items & get_mediaitems() { return items_; }

    size_t next_rId()
    {
        return next_rId_++;
    }

    std::pair<std::wstring, std::wstring> add_drawing_xml(std::wstring const & content, xlsx_drawings_ptr drawings)
    {
        const std::wstring id = boost::lexical_cast<std::wstring>(next_drawing_id_++);
        const std::wstring fileName = std::wstring(L"drawing") + id + L".xml";
       
		drawings_.push_back(drawing_elm(fileName, content, drawings));
       
		const std::wstring rId = std::wstring(L"rId") + id;//rDrId
        return std::pair<std::wstring, std::wstring>(fileName, rId);
    }
    const std::vector<drawing_elm> & content() const
    {
        return drawings_;
    }

	xlsx_drawings_ptr get_drawings();
private:
    external_items & items_;
    size_t next_rId_;
    
    std::vector<drawing_elm> drawings_;

    size_t next_drawing_id_;
};

xlsx_drawing_context_handle::xlsx_drawing_context_handle(external_items & items)
: impl_(new xlsx_drawing_context_handle::Impl(items))
{
}

xlsx_drawing_context_handle::~xlsx_drawing_context_handle()
{
}
std::pair<std::wstring, std::wstring> xlsx_drawing_context_handle::add_drawing_xml(std::wstring const & content, xlsx_drawings_ptr drawings )
{
    return impl_->add_drawing_xml(content, drawings);
}

const std::vector<drawing_elm> & xlsx_drawing_context_handle::content() const
{
    return impl_->content();
}

//---------------------------------------------------------------------------------------

xlsx_drawing_context::xlsx_drawing_context(xlsx_drawing_context_handle & h)
 : handle_(h), xlsx_drawings_(xlsx_drawings::create()), count_object(0)
{    
}

bool xlsx_drawing_context::start_drawing(int type)
{
	switch(type)
	{
	case 0x0000: // Group
	case 0x0001: // Line
	case 0x0002: // Rectangle
	case 0x0003: // Oval
	case 0x0004: // Arc
		start_shape(type); return true;
	case 0x0005: // Chart  
	case 0x0006: // Text
	case 0x0007: // Button
		break;
	case 0x0008: // Picture
		start_image(); return true;
	case 0x0009: // Polygon:
	case 0x000B: // Checkbox
	case 0x000C: // Radio button
	case 0x000D: // Edit box
	case 0x000E: // Label
	case 0x000F: // Dialog box
	case 0x0010: // Spin control
	case 0x0011: // Scrollbar
	case 0x0012: // List
	case 0x0013: // Group box
	case 0x0014: // Dropdown list
	case 0x0019: // Note
	case 0x001E: // OfficeArt object
		break;
	}
	return false;

}

void xlsx_drawing_context::start_image()
{
	_drawing_state st;
	drawing_state.push_back(st);

	drawing_state.back().type = external_items::typeImage;
	
	count_object++;
}

void xlsx_drawing_context::start_shape(int type)
{
	_drawing_state st;
	drawing_state.push_back(st);

	drawing_state.back().type = external_items::typeShape;

	count_object++;
}

void xlsx_drawing_context::set_id(int id)
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().id = id;
}
void xlsx_drawing_context::set_FlipH()
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().flipH = true;
}
void xlsx_drawing_context::set_FlipV()
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().flipV = true;
}
void xlsx_drawing_context::set_shape_id(int id)
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().shape_id = id;
}

void xlsx_drawing_context::end_drawing()
{
	if (drawing_state.size() < 1 )return;

	std::wstringstream strm;

	switch(drawing_state.back().type)
	{
	case external_items::typeImage:
		if (!drawing_state.back().image_target.empty())
		{
			bool isIternal = false;
			std::wstring rId = handle_.impl_->get_mediaitems().find_image( drawing_state.back().image_target, isIternal);
			
			serialize_pic(rId);
			serialize(strm);
			xlsx_drawings_->add(strm.str(), isIternal, 	rId , drawing_state.back().image_target, drawing_state.back().type);
		}
		break;
	}

	drawing_state.pop_back();

}
void xlsx_drawing_context::serialize_pic(std::wstring rId)
{
	std::wstringstream strm;

	CP_XML_WRITER(strm)    
	{
		CP_XML_NODE(L"xdr:pic")
		{ 
			CP_XML_NODE(L"xdr:nvPicPr")
			{
				CP_XML_NODE(L"xdr:cNvPr")
				{
					if (drawing_state.back().id >= 0) CP_XML_ATTR(L"id", drawing_state.back().id);
					CP_XML_ATTR(L"name", L"Picture_" + rId.substr(5));

					if (!drawing_state.back().hyperlink.empty())
					{
						CP_XML_NODE(L"a:hlinkClick")
						{
							CP_XML_ATTR(L"xmlns:r", L"http://schemas.openxmlformats.org/officeDocument/2006/relationships");
							//CP_XML_ATTR(L"xmlns:a", L"http://schemas.openxmlformats.org/drawingml/2006/main");
							
							CP_XML_ATTR(L"r:id", drawing_state.back().hyperlink);
						}
					}
				}
				CP_XML_NODE(L"xdr:cNvPicPr")
				{
					CP_XML_NODE(L"a:picLocks")
					{
						CP_XML_ATTR(L"noChangeArrowheads", 1);
						CP_XML_ATTR(L"noChangeAspect", 1);
					}
				}
			}
			CP_XML_NODE(L"xdr:blipFill")
			{
				CP_XML_NODE(L"a:blip")
				{
					CP_XML_ATTR(L"xmlns:r", L"http://schemas.openxmlformats.org/officeDocument/2006/relationships");
					CP_XML_ATTR(L"r:embed", rId);
				}
				CP_XML_NODE(L"a:srcRect");

				CP_XML_NODE(L"a:stretch")
				{
					CP_XML_NODE(L"a:fillRect");
				}
			}
			CP_XML_NODE(L"xdr:spPr")
			{
				CP_XML_NODE(L"a:xfrm")
				{
					CP_XML_NODE(L"a:off")
					{
						CP_XML_ATTR(L"y", 0);
						CP_XML_ATTR(L"x", 0);
					}
					CP_XML_NODE(L"a:ext")
					{
						CP_XML_ATTR(L"cy", 0);
						CP_XML_ATTR(L"cx", 0);
					}
				}
				CP_XML_NODE(L"a:prstGeom")
				{
					CP_XML_ATTR(L"prst", "rect");
					CP_XML_NODE(L"a:avLst");
				}

				CP_XML_NODE(L"a:noFill");
			}
		}
	}

	drawing_state.back().shape = strm.str();
}
void xlsx_drawing_context::serialize(std::wostream & stream)
{
	CP_XML_WRITER(stream)    
	{
		CP_XML_NODE(L"xdr:twoCellAnchor")
		{ 
			CP_XML_ATTR(L"editAs", L"oneCell");

			CP_XML_STREAM() << drawing_state.back().anchor;
			CP_XML_STREAM() << drawing_state.back().shape;
			
			CP_XML_NODE(L"xdr:clientData");
		}
	}
}

void xlsx_drawing_context::set_anchor(std::wstring & str)
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().anchor = str;
}
void xlsx_drawing_context::set_image(std::wstring & str)
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().image_target = str;
}

void xlsx_drawing_context::set_hyperlink(std::wstring & str)
{
	if (drawing_state.size() < 1 )return;

	std::wstring hId=std::wstring(L"hId") + boost::lexical_cast<std::wstring>(hlinks_.size()+1);
	
	std::wstring href_correct = xml::utils::replace_text_to_xml(str);

	_hlink_desc desc = {hId, href_correct};

	hlinks_.push_back(desc);
	drawing_state.back().hyperlink = hId;

	xlsx_drawings_->add( false, hId , href_correct, external_items::typeHyperlink);
}

void xlsx_drawing_context::set_properties(std::wstring & str)
{
	if (drawing_state.size() < 1 )return;
	drawing_state.back().shape = str;
}

bool xlsx_drawing_context::empty()
{
	return xlsx_drawings_->empty();
}

xlsx_drawings_ptr xlsx_drawing_context::get_drawings()
{
    return xlsx_drawings_;
}

}
