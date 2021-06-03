#include "TableWriter.h"

TableWriter::TableWriter(CTableElement *pTableElement) :
    m_pTableElement(pTableElement)
{

}

void TableWriter::Convert(PPTX::Logic::GraphicFrame &oGraphicFrame)
{
    if (!m_pTableElement)
        return;

    oGraphicFrame.nvGraphicFramePr = new PPTX::Logic::NvGraphicFramePr;
    FillNvGraphicFramePr(oGraphicFrame.nvGraphicFramePr.get2());

    oGraphicFrame.xfrm = new PPTX::Logic::Xfrm;
    FillXfrm(oGraphicFrame.xfrm.get2());

    oGraphicFrame.table = new PPTX::Logic::Table;
    FillTable(oGraphicFrame.table.get2());
}

void TableWriter::FillNvGraphicFramePr(PPTX::Logic::NvGraphicFramePr& oNvGFPr)
{
    oNvGFPr.cNvPr.id = m_pTableElement->m_lID;
    oNvGFPr.cNvPr.name = m_pTableElement->m_sName;

    // not works in full
    // graphicFrameLocks

    PPTX::Logic::Ext ext;
    ext.uri = L"{D42A27DB-BD31-4B8C-83A1-F6EECF244321}";
    oNvGFPr.nvPr.extLst.push_back(ext);
}

void TableWriter::FillXfrm(PPTX::Logic::Xfrm &oXFRM)
{
    oXFRM.offX = int(m_pTableElement->m_rcAnchor.left * 1588);
    oXFRM.offY = int(m_pTableElement->m_rcAnchor.top * 1588);

    oXFRM.extX = int(m_pTableElement->m_rcAnchor.right * 983);
    oXFRM.extY = int(m_pTableElement->m_rcAnchor.bottom * 1398);
}

void TableWriter::FillTable(PPTX::Logic::Table &oTable)
{
    std::vector<CElement*> arrCells, arrSpliters;
    prepareShapes(arrCells, arrSpliters);

    auto height = getHeight(arrCells);
}

std::vector<int> TableWriter::getHeight(std::vector<CElement*> &arrCells)
{
    std::vector<int> height;
    int currentHeight = 0;
    for (auto* cell : arrCells)
    {
        auto pShapeEl = dynamic_cast<CShapeElement*>(cell);
//        if (pShapeEl->)
    }

    return height;
}

void TableWriter::prepareShapes(std::vector<CElement*> &arrCells, std::vector<CElement *> &arrSpliters)
{
    for (const auto& ptrShape : m_pTableElement->m_pChildElements)
    {
        auto pShapeEl = dynamic_cast<CShapeElement*>(ptrShape.get());
        switch (pShapeEl->m_lShapeType)
        {
        case 1:
            arrCells.push_back(pShapeEl);
            break;
        case 20:
            arrSpliters.push_back(pShapeEl);
            break;
        }
    }
}
