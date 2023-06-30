#include "CObjectBase.h"
#include "../CSvgFile.h"

namespace SVG
{
	CRenderedObject::CRenderedObject(const NSCSS::CNode &oData, CRenderedObject *pParent)
		: CObject(oData), m_pParent(pParent)
	{
		SetDefaultStyles();
	}

	CRenderedObject::CRenderedObject(XmlUtils::CXmlNode &oNode, CRenderedObject *pParent)
		: CObject(oNode), m_pParent(pParent)
	{
		SetDefaultStyles();
	}

	CRenderedObject::~CRenderedObject()
	{}

	ObjectType CRenderedObject::GetType() const
	{
		return RendererObject;
	}

	std::vector<NSCSS::CNode> CRenderedObject::GetFullPath() const
	{
		if (NULL == m_pParent)
			return {m_oXmlNode};

		std::vector<NSCSS::CNode> arObjects = m_pParent->GetFullPath();
		arObjects.push_back(m_oXmlNode);
		return arObjects;
	}

	void CRenderedObject::SetDefaultStyles()
	{
		m_oStyles.m_oStroke.m_oLineCap.SetMapping({std::make_pair(L"butt", Aggplus::LineCapFlat), std::make_pair(L"round", Aggplus::LineCapRound), std::make_pair(L"square", Aggplus::LineCapSquare)});
		m_oStyles.m_oStroke.m_oLineCap = Aggplus::LineCapFlat;

		m_oStyles.m_oStroke.m_oLineJoin.SetMapping({std::make_pair(L"arcs", Aggplus::LineJoinMiter), std::make_pair(L"bevel", Aggplus::LineJoinBevel), std::make_pair(L"miter", Aggplus::LineJoinMiter), std::make_pair(L"miter-clip", Aggplus::LineJoinMiterClipped), std::make_pair(L"round", Aggplus::LineJoinRound)});
		m_oStyles.m_oStroke.m_oLineCap = Aggplus::LineJoinMiter;
	}

	void CRenderedObject::SetStroke(const std::map<std::wstring, std::wstring> &mAttributes, unsigned short ushLevel, bool bHardMode)
	{
		if (mAttributes.end() != mAttributes.find(L"stroke"))
			m_oStyles.m_oStroke.m_oColor.SetValue(mAttributes.at(L"stroke"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"stroke-width"))
			m_oStyles.m_oStroke.m_oWidth.SetValue(mAttributes.at(L"stroke-width"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"stroke-dasharray"))
			m_oStyles.m_oStroke.m_arDash = NSCSS::NS_STATIC_FUNCTIONS::ReadDoubleValues(mAttributes.at(L"stroke-dasharray"));

		if (mAttributes.end() != mAttributes.find(L"stroke-linecap"))
			m_oStyles.m_oStroke.m_oLineCap.SetValue(mAttributes.at(L"stroke-linecap"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"stroke-linejoin"))
			m_oStyles.m_oStroke.m_oLineJoin.SetValue(mAttributes.at(L"stroke-linejoin"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"stroke-opacity"))
			m_oStyles.m_oStroke.m_oColor.SetOpacity(mAttributes.at(L"stroke-opacity"), ushLevel, bHardMode);
	}

	void CRenderedObject::SetFill(const std::map<std::wstring, std::wstring> &mAttributes, unsigned short ushLevel, bool bHardMode)
	{
		if (mAttributes.end() != mAttributes.find(L"fill"))
			m_oStyles.m_oFill.SetValue(mAttributes.at(L"fill"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"fill-opacity"))
			m_oStyles.m_oFill.SetOpacity(mAttributes.at(L"fill-opacity"), ushLevel, bHardMode);

		if (mAttributes.end() != mAttributes.find(L"opacity"))
			m_oStyles.m_oFill.SetOpacity(mAttributes.at(L"opacity"), ushLevel, bHardMode);
	}

	void CRenderedObject::SetTransform(const std::map<std::wstring, std::wstring> &mAttributes, unsigned short ushLevel, bool bHardMode)
	{
		if (mAttributes.end() != mAttributes.find(L"transform"))
			m_oStyles.m_oTransform.SetMatrix(mAttributes.at(L"transform"), ushLevel, bHardMode);
	}

	void CRenderedObject::SetClip(const std::map<std::wstring, std::wstring> &mAttributes, unsigned short ushLevel, bool bHardMode)
	{
		if (mAttributes.end() != mAttributes.find(L"clip-path"))
			m_oStyles.m_oClip.m_oHref.SetValue(mAttributes.at(L"clip-path"), ushLevel, bHardMode);
		if (mAttributes.end() != mAttributes.find(L"clip-rule"))
			m_oStyles.m_oClip.m_oRule.SetValue(mAttributes.at(L"clip-rule"), std::vector<std::wstring>{L"nonzero", L"evenodd"}, ushLevel, bHardMode);
	}

	void CRenderedObject::SetMask(const std::map<std::wstring, std::wstring> &mAttributes, unsigned short ushLevel, bool bHardMode)
	{
		if (mAttributes.end() != mAttributes.find(L"mask"))
			m_oStyles.m_oMask.SetValue(mAttributes.at(L"mask"), ushLevel, bHardMode);
	}

	void CRenderedObject::StartPath(IRenderer *pRenderer, const CSvgFile *pFile, CommandeMode oMode) const
	{
		Apply(pRenderer, &m_oStyles.m_oClip, pFile);
		ApplyMask(pRenderer, &m_oStyles.m_oMask, pFile);

		if (CommandeModeClip == oMode)
			return;

		pRenderer->BeginCommand(c_nPathType);
		pRenderer->PathCommandStart();
	}

	void CRenderedObject::EndPath(IRenderer *pRenderer, const CSvgFile *pFile, CommandeMode oMode, const TSvgStyles* pOtherStyles) const
	{
		if (CommandeModeClip == oMode)
			return;

		int nPathType = 0;
		Aggplus::CMatrix oOldMatrix(1., 0., 0., 1., 0, 0);

		if (NULL == pOtherStyles)
			ApplyStyle(pRenderer, &m_oStyles, pFile, nPathType, oOldMatrix);
		else
		{
			TSvgStyles oNewStyles(m_oStyles);
			oNewStyles += *pOtherStyles;
			ApplyStyle(pRenderer, &oNewStyles, pFile, nPathType, oOldMatrix);
		}

		pRenderer->DrawPath(nPathType);
		pRenderer->EndCommand(c_nPathType);
		pRenderer->PathCommandEnd();

		if (oMode != CommandeModeMask)
		{
			pRenderer->BeginCommand(c_nResetMaskType);
			pRenderer->EndCommand(c_nResetMaskType);
		}

		pRenderer->SetTransform(oOldMatrix.sx(), oOldMatrix.shy(), oOldMatrix.shx(), oOldMatrix.sy(), oOldMatrix.tx(), oOldMatrix.ty());
	}

	bool CRenderedObject::Apply(IRenderer *pRenderer, const TStroke *pStroke, bool bUseDefault) const
	{
		if (NULL == pRenderer || NULL == pStroke || NSCSS::NSProperties::ColorType::ColorNone == pStroke->m_oColor.GetType() || (!bUseDefault && ((pStroke->m_oWidth.Empty() || pStroke->m_oWidth.Zero()) && pStroke->m_oColor.Empty())))
		{
			pRenderer->put_PenSize(0);
			return false;
		}

		double dStrokeWidth = pStroke->m_oWidth.ToDouble(NSCSS::Pixel);

		if (0. == dStrokeWidth)
			dStrokeWidth = 1.;

		int nColor = (pStroke->m_oColor.Empty() || NSCSS::NSProperties::ColorType::ColorNone == pStroke->m_oColor.GetType()) ? 0 : pStroke->m_oColor.ToInt();

		pRenderer->put_PenSize(dStrokeWidth);
		pRenderer->put_PenColor(nColor);
		pRenderer->put_PenAlpha(255. * pStroke->m_oColor.GetOpacity());

		if (!pStroke->m_arDash.empty())
		{
			pRenderer->PenDashPattern((double*)pStroke->m_arDash.data(), pStroke->m_arDash.size());
			pRenderer->put_PenDashStyle(Aggplus::DashStyleCustom);
		}
		else
			pRenderer->put_PenDashStyle(Aggplus::DashStyleSolid);

		if (!pStroke->m_oLineCap.Empty())
		{
			pRenderer->put_PenLineStartCap(pStroke->m_oLineCap.ToInt());
			pRenderer->put_PenLineEndCap(pStroke->m_oLineCap.ToInt());
		}

		if (!pStroke->m_oLineJoin.Empty())
			pRenderer->put_PenLineJoin(pStroke->m_oLineJoin.ToInt());

		return true;
	}

	bool CRenderedObject::Apply(IRenderer *pRenderer, const NSCSS::NSProperties::CColor *pFill, const CSvgFile *pFile, bool bUseDefault) const
	{
		if (NULL == pRenderer || NULL == pFill || NSCSS::NSProperties::ColorType::ColorNone == pFill->GetType() || (!bUseDefault && pFill->Empty()))
		{
			pRenderer->put_BrushType(c_BrushTypeNoFill);
			return false;
		}
		else if (NSCSS::NSProperties::ColorType::ColorHEX == pFill->GetType() ||
				 NSCSS::NSProperties::ColorType::ColorRGB == pFill->GetType())
		{
			pRenderer->put_BrushColor1((pFill->Empty() && bUseDefault) ? 0 : pFill->ToInt());
			pRenderer->put_BrushType(c_BrushTypeSolid);
		}
		else if (NSCSS::NSProperties::ColorType::ColorUrl == pFill->GetType())
		{
			if (!ApplyDef(pRenderer, pFile, pFill->ToWString()))
			{
				if (bUseDefault)
				{
					pRenderer->put_BrushColor1(0);
					pRenderer->put_BrushType(c_BrushTypeSolid);
				}
				else
					return false;
			}
		}
		else if (bUseDefault)
		{
			pRenderer->put_BrushColor1(0);
			pRenderer->put_BrushType(c_BrushTypeSolid);
		}

		pRenderer->put_BrushAlpha1(255. * pFill->GetOpacity());

		return true;
	}

	bool CRenderedObject::Apply(IRenderer *pRenderer, const NSCSS::NSProperties::CTransform *pTransform, Aggplus::CMatrix& oOldMatrix) const
	{
		if (NULL == pRenderer || NULL == pTransform)
			return false;

		double dM11, dM12, dM21, dM22, dRx, dRy;

		pRenderer->GetTransform(&dM11, &dM12, &dM21, &dM22, &dRx, &dRy);

		oOldMatrix.SetElements(dM11, dM12, dM21, dM22, dRx, dRy);

		Aggplus::CMatrix oMatrix = pTransform->GetMatrix().GetFinalValue();

		oMatrix.Multiply(&oOldMatrix, Aggplus::MatrixOrderAppend);

		pRenderer->SetTransform(oMatrix.sx(), oMatrix.shy(), oMatrix.shx(), oMatrix.sy(), oMatrix.tx(), oMatrix.ty());

		return true;
	}

	bool CRenderedObject::Apply(IRenderer *pRenderer, const TClip *pClip, const CSvgFile *pFile) const
	{
		if (NULL == pRenderer || NULL == pClip || NULL == pFile)
			return false;

		pRenderer->BeginCommand(c_nResetClipType);
		pRenderer->EndCommand(c_nResetClipType);

		if (pClip->m_oRule == L"evenodd")
			pRenderer->put_ClipMode(c_nClipRegionTypeEvenOdd);
		else
			pRenderer->put_ClipMode(c_nClipRegionTypeWinding);

		if (pClip->m_oHref.Empty() || NSCSS::NSProperties::ColorType::ColorUrl != pClip->m_oHref.GetType())
			return true;

		return ApplyDef(pRenderer, pFile, pClip->m_oHref.ToWString());
	}

	bool CRenderedObject::ApplyMask(IRenderer *pRenderer, const NSCSS::NSProperties::CColor *pMask, const CSvgFile *pFile) const
	{
		if (NULL == pRenderer || NULL == pMask || NULL == pFile || NSCSS::NSProperties::ColorType::ColorUrl != pMask->GetType())
			return false;

		return ApplyDef(pRenderer, pFile, pMask->ToWString());
	}

	bool CRenderedObject::ApplyDef(IRenderer *pRenderer, const CSvgFile *pFile, const std::wstring &wsUrl) const
	{
		if (NULL == pRenderer || NULL == pFile || wsUrl.empty())
			return false;

		CAppliedObject *pDefObject = dynamic_cast<CAppliedObject*>(pFile->GetMarkedObject(wsUrl));

		if (NULL == pDefObject)
			return false;

		return pDefObject->Apply(pRenderer, pFile, GetBounds());
	}

	CAppliedObject::CAppliedObject(XmlUtils::CXmlNode &oNode)
		: CObject(oNode)
	{}

	CAppliedObject::~CAppliedObject()
	{}

	ObjectType CAppliedObject::GetType() const
	{
		return AppliedObject;
	}

}
