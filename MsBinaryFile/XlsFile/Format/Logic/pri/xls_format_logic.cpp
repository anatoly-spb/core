/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "../Biff_records/AlRuns.cpp"
#include "../Biff_records/Area.cpp"
#include "../Biff_records/AreaFormat.cpp"
#include "../Biff_records/Array.cpp"
#include "../Biff_records/AttachedLabel.cpp"
#include "../Biff_records/AutoFilter.cpp"
#include "../Biff_records/AutoFilter12.cpp"
#include "../Biff_records/AutoFilterInfo.cpp"
#include "../Biff_records/AxcExt.cpp"
#include "../Biff_records/AxesUsed.cpp"
#include "../Biff_records/Axis.cpp"
#include "../Biff_records/AxisLine.cpp"
#include "../Biff_records/AxisParent.cpp"
#include "../Biff_records/Backup.cpp"
#include "../Biff_records/Bar.cpp"
#include "../Biff_records/Begin.cpp"
#include "../Biff_records/BiffRecord.cpp"
#include "../Biff_records/BiffRecordContinued.cpp"
#include "../Biff_records/BiffRecordSplit.cpp"
#include "../Biff_records/BigName.cpp"
#include "../Biff_records/BkHim.cpp"
#include "../Biff_records/Blank.cpp"
#include "../Biff_records/BOF.cpp"
#include "../Biff_records/BookBool.cpp"
#include "../Biff_records/BookExt.cpp"
#include "../Biff_records/BoolErr.cpp"
#include "../Biff_records/BopPop.cpp"
#include "../Biff_records/BopPopCustom.cpp"
#include "../Biff_records/BottomMargin.cpp"
#include "../Biff_records/BoundSheet8.cpp"
#include "../Biff_records/BRAI.cpp"
#include "../Biff_records/BuiltInFnGroupCount.cpp"
#include "../Biff_records/CalcCount.cpp"
#include "../Biff_records/CalcDelta.cpp"
#include "../Biff_records/CalcIter.cpp"
#include "../Biff_records/CalcMode.cpp"
#include "../Biff_records/CalcPrecision.cpp"
#include "../Biff_records/CalcRefMode.cpp"
#include "../Biff_records/CalcSaveRecalc.cpp"
#include "../Biff_records/CatLab.cpp"
#include "../Biff_records/CatSerRange.cpp"
#include "../Biff_records/CellWatch.cpp"
#include "../Biff_records/CF.cpp"
#include "../Biff_records/CF12.cpp"
#include "../Biff_records/CFEx.cpp"
#include "../Biff_records/Chart.cpp"
#include "../Biff_records/Chart3d.cpp"
#include "../Biff_records/Chart3DBarShape.cpp"
#include "../Biff_records/ChartFormat.cpp"
#include "../Biff_records/ChartFrtInfo.cpp"
#include "../Biff_records/CodeName.cpp"
#include "../Biff_records/CodePage.cpp"
#include "../Biff_records/ColInfo.cpp"
#include "../Biff_records/Compat12.cpp"
#include "../Biff_records/CompressPictures.cpp"
#include "../Biff_records/CondFmt.cpp"
#include "../Biff_records/CondFmt12.cpp"
#include "../Biff_records/Continue.cpp"
#include "../Biff_records/ContinueBigName.cpp"
#include "../Biff_records/ContinueFrt.cpp"
#include "../Biff_records/ContinueFrt11.cpp"
#include "../Biff_records/ContinueFrt12.cpp"
#include "../Biff_records/Country.cpp"
#include "../Biff_records/CrErr.cpp"
#include "../Biff_records/CRN.cpp"
#include "../Biff_records/CrtLayout12.cpp"
#include "../Biff_records/CrtLayout12A.cpp"
#include "../Biff_records/CrtLine.cpp"
#include "../Biff_records/CrtLink.cpp"
#include "../Biff_records/CrtMlFrt.cpp"
#include "../Biff_records/CrtMlFrtContinue.cpp"
#include "../Biff_records/Dat.cpp"
#include "../Biff_records/DataFormat.cpp"
#include "../Biff_records/DataLabExt.cpp"
#include "../Biff_records/DataLabExtContents.cpp"
#include "../Biff_records/Date1904.cpp"
#include "../Biff_records/DBCell.cpp"
#include "../Biff_records/DbOrParamQry.cpp"
#include "../Biff_records/DBQueryExt.cpp"
#include "../Biff_records/DCon.cpp"
#include "../Biff_records/DConBin.cpp"
#include "../Biff_records/DConn.cpp"
#include "../Biff_records/DConName.cpp"
#include "../Biff_records/DConRef.cpp"
#include "../Biff_records/DefaultRowHeight.cpp"
#include "../Biff_records/DefaultText.cpp"
#include "../Biff_records/DefColWidth.cpp"
#include "../Biff_records/Dimensions.cpp"
#include "../Biff_records/DocRoute.cpp"
#include "../Biff_records/DropBar.cpp"
#include "../Biff_records/DropDownObjIds.cpp"
#include "../Biff_records/DSF.cpp"
#include "../Biff_records/Dv.cpp"
#include "../Biff_records/DVal.cpp"
#include "../Biff_records/DXF.cpp"
#include "../Biff_records/DxGCol.cpp"
#include "../Biff_records/End.cpp"
#include "../Biff_records/EndObject.cpp"
#include "../Biff_records/EntExU2.cpp"
#include "../Biff_records/EOF.cpp"
#include "../Biff_records/Excel9File.cpp"
#include "../Biff_records/ExternName.cpp"
#include "../Biff_records/ExternSheet.cpp"
#include "../Biff_records/ExtSST.cpp"
#include "../Biff_records/ExtString.cpp"
#include "../Biff_records/Fbi.cpp"
#include "../Biff_records/Fbi2.cpp"
#include "../Biff_records/Feat.cpp"
#include "../Biff_records/FeatHdr.cpp"
#include "../Biff_records/FeatHdr11.cpp"
#include "../Biff_records/Feature11.cpp"
#include "../Biff_records/Feature12.cpp"
#include "../Biff_records/FilePass.cpp"
#include "../Biff_records/FileSharing.cpp"
#include "../Biff_records/FilterMode.cpp"
#include "../Biff_records/FnGroupName.cpp"
#include "../Biff_records/FnGrp12.cpp"
#include "../Biff_records/Font.cpp"
#include "../Biff_records/FontX.cpp"
#include "../Biff_records/Footer.cpp"
#include "../Biff_records/ForceFullCalculation.cpp"
#include "../Biff_records/Format.cpp"
#include "../Biff_records/Formula.cpp"
#include "../Biff_records/Frame.cpp"
#include "../Biff_records/FrtFontList.cpp"
#include "../Biff_records/GelFrame.cpp"
#include "../Biff_records/GridSet.cpp"
#include "../Biff_records/GUIDTypeLib.cpp"
#include "../Biff_records/Guts.cpp"
#include "../Biff_records/HCenter.cpp"
#include "../Biff_records/Header.cpp"
#include "../Biff_records/HeaderFooter.cpp"
#include "../Biff_records/HFPicture.cpp"
#include "../Biff_records/HideObj.cpp"
#include "../Biff_records/HLink.cpp"
#include "../Biff_records/HLinkTooltip.cpp"
#include "../Biff_records/HorizontalPageBreaks.cpp"
#include "../Biff_records/IFmtRecord.cpp"
#include "../Biff_records/Index.cpp"
#include "../Biff_records/InterfaceEnd.cpp"
#include "../Biff_records/InterfaceHdr.cpp"
#include "../Biff_records/Intl.cpp"
#include "../Biff_records/Label.cpp"
#include "../Biff_records/LabelSst.cpp"
#include "../Biff_records/Lbl.cpp"
#include "../Biff_records/LeftMargin.cpp"
#include "../Biff_records/Legend.cpp"
#include "../Biff_records/LegendException.cpp"
#include "../Biff_records/Lel.cpp"
#include "../Biff_records/Line.cpp"
#include "../Biff_records/LineFormat.cpp"
#include "../Biff_records/List12.cpp"
#include "../Biff_records/LPr.cpp"
#include "../Biff_records/LRng.cpp"
#include "../Biff_records/MarkerFormat.cpp"
#include "../Biff_records/MDB.cpp"
#include "../Biff_records/MDTInfo.cpp"
#include "../Biff_records/MDXKPI.cpp"
#include "../Biff_records/MDXProp.cpp"
#include "../Biff_records/MDXSet.cpp"
#include "../Biff_records/MDXStr.cpp"
#include "../Biff_records/MDXTuple.cpp"
#include "../Biff_records/MergeCells.cpp"
#include "../Biff_records/Mms.cpp"
#include "../Biff_records/MsoDrawing.cpp"
#include "../Biff_records/MsoDrawingGroup.cpp"
#include "../Biff_records/MsoDrawingSelection.cpp"
#include "../Biff_records/MTRSettings.cpp"
#include "../Biff_records/MulBlank.cpp"
#include "../Biff_records/MulRk.cpp"
#include "../Biff_records/NameCmt.cpp"
#include "../Biff_records/NameFnGrp12.cpp"
#include "../Biff_records/NamePublish.cpp"
#include "../Biff_records/Note.cpp"
#include "../Biff_records/Number.cpp"
#include "../Biff_records/Obj.cpp"
#include "../Biff_records/ObjectLink.cpp"
#include "../Biff_records/ObjProtect.cpp"
#include "../Biff_records/ObNoMacros.cpp"
#include "../Biff_records/ObProj.cpp"
#include "../Biff_records/OleDbConn.cpp"
#include "../Biff_records/OleObjectSize.cpp"
#include "../Biff_records/Palette.cpp"
#include "../Biff_records/Pane.cpp"
#include "../Biff_records/Password.cpp"
#include "../Biff_records/PhoneticInfo.cpp"
#include "../Biff_records/PicF.cpp"
#include "../Biff_records/Pie.cpp"
#include "../Biff_records/PieFormat.cpp"
#include "../Biff_records/PivotChartBits.cpp"
#include "../Biff_records/PlotArea.cpp"
#include "../Biff_records/PlotGrowth.cpp"
#include "../Biff_records/Pls.cpp"
#include "../Biff_records/PLV.cpp"
#include "../Biff_records/Pos.cpp"
#include "../Biff_records/PrintGrid.cpp"
#include "../Biff_records/PrintRowCol.cpp"
#include "../Biff_records/PrintSize.cpp"
#include "../Biff_records/Prot4Rev.cpp"
#include "../Biff_records/Prot4RevPass.cpp"
#include "../Biff_records/Protect.cpp"
#include "../Biff_records/Qsi.cpp"
#include "../Biff_records/Qsif.cpp"
#include "../Biff_records/Qsir.cpp"
#include "../Biff_records/QsiSXTag.cpp"
#include "../Biff_records/Radar.cpp"
#include "../Biff_records/RadarArea.cpp"
#include "../Biff_records/RealTimeData.cpp"
#include "../Biff_records/RecalcId.cpp"
#include "../Biff_records/RecipName.cpp"
#include "../Biff_records/RefreshAll.cpp"
#include "../Biff_records/RichTextStream.cpp"
#include "../Biff_records/RightMargin.cpp"
#include "../Biff_records/RK.cpp"
#include "../Biff_records/Row.cpp"
#include "../Biff_records/RRSort.cpp"
#include "../Biff_records/RRTabId.cpp"
#include "../Biff_records/SBaseRef.cpp"
#include "../Biff_records/Scatter.cpp"
#include "../Biff_records/SCENARIO.cpp"
#include "../Biff_records/ScenarioProtect.cpp"
#include "../Biff_records/ScenMan.cpp"
#include "../Biff_records/Scl.cpp"
#include "../Biff_records/Selection.cpp"
#include "../Biff_records/SerAuxErrBar.cpp"
#include "../Biff_records/SerAuxTrend.cpp"
#include "../Biff_records/SerFmt.cpp"
#include "../Biff_records/Series.cpp"
#include "../Biff_records/SeriesList.cpp"
#include "../Biff_records/SeriesText.cpp"
#include "../Biff_records/SerParent.cpp"
#include "../Biff_records/SerToCrt.cpp"
#include "../Biff_records/Setup.cpp"
#include "../Biff_records/ShapePropsStream.cpp"
#include "../Biff_records/SheetExt.cpp"
#include "../Biff_records/ShrFmla.cpp"
#include "../Biff_records/ShtProps.cpp"
#include "../Biff_records/SIIndex.cpp"
#include "../Biff_records/Sort.cpp"
#include "../Biff_records/SortData.cpp"
#include "../Biff_records/SST.cpp"
#include "../Biff_records/StartObject.cpp"
#include "../Biff_records/String.cpp"
#include "../Biff_records/Style.cpp"
#include "../Biff_records/StyleExt.cpp"
#include "../Biff_records/SupBook.cpp"
#include "../Biff_records/Surf.cpp"
#include "../Biff_records/SXAddl.cpp"
#include "../Biff_records/SXDI.cpp"
#include "../Biff_records/SxDXF.cpp"
#include "../Biff_records/SXEx.cpp"
#include "../Biff_records/SxFilt.cpp"
#include "../Biff_records/SxFormat.cpp"
#include "../Biff_records/SxItm.cpp"
#include "../Biff_records/SxIvd.cpp"
#include "../Biff_records/SXLI.cpp"
#include "../Biff_records/SXPI.cpp"
#include "../Biff_records/SXPIEx.cpp"
#include "../Biff_records/SxRule.cpp"
#include "../Biff_records/SxSelect.cpp"
#include "../Biff_records/SXStreamID.cpp"
#include "../Biff_records/SXString.cpp"
#include "../Biff_records/SXTbl.cpp"
#include "../Biff_records/SxTbpg.cpp"
#include "../Biff_records/SXTBRGIITM.cpp"
#include "../Biff_records/SXTH.cpp"
#include "../Biff_records/Sxvd.cpp"
#include "../Biff_records/SXVDEx.cpp"
#include "../Biff_records/SXVDTEx.cpp"
#include "../Biff_records/SXVI.cpp"
#include "../Biff_records/SxView.cpp"
#include "../Biff_records/SXViewEx.cpp"
#include "../Biff_records/SXViewEx9.cpp"
#include "../Biff_records/SXViewLink.cpp"
#include "../Biff_records/SXVS.cpp"
#include "../Biff_records/Sync.cpp"
#include "../Biff_records/Table.cpp"
#include "../Biff_records/TableStyle.cpp"
#include "../Biff_records/TableStyleElement.cpp"
#include "../Biff_records/TableStyles.cpp"
#include "../Biff_records/Template.cpp"
#include "../Biff_records/Text.cpp"
#include "../Biff_records/TextPropsStream.cpp"
#include "../Biff_records/Theme.cpp"
#include "../Biff_records/Tick.cpp"
#include "../Biff_records/TopMargin.cpp"
#include "../Biff_records/TxO.cpp"
#include "../Biff_records/TxtQry.cpp"
#include "../Biff_records/Uncalced.cpp"
#include "../Biff_records/Units.cpp"
#include "../Biff_records/UserBView.cpp"
#include "../Biff_records/UserSViewBegin.cpp"
#include "../Biff_records/UserSViewEnd.cpp"
#include "../Biff_records/UsesELFs.cpp"
#include "../Biff_records/ValueRange.cpp"
#include "../Biff_records/VCenter.cpp"
#include "../Biff_records/VerticalPageBreaks.cpp"
#include "../Biff_records/WebPub.cpp"
#include "../Biff_records/Window1.cpp"
#include "../Biff_records/Window2.cpp"
#include "../Biff_records/WinProtect.cpp"
#include "../Biff_records/WOpt.cpp"
#include "../Biff_records/WriteAccess.cpp"
#include "../Biff_records/WriteProtect.cpp"
#include "../Biff_records/WsBool.cpp"
#include "../Biff_records/XCT.cpp"
#include "../Biff_records/XF.cpp"
#include "../Biff_records/XFCRC.cpp"
#include "../Biff_records/XFExt.cpp"
#include "../Biff_records/YMult.cpp"
#include "../Biff_records/FrtWrapper.cpp"
#include "../Biff_records/SxBool.cpp"
#include "../Biff_records/SXDB.cpp"
#include "../Biff_records/SXDBB.cpp"
#include "../Biff_records/SXDBEx.cpp"
#include "../Biff_records/SXDtr.cpp"
#include "../Biff_records/SxErr.cpp"
#include "../Biff_records/SXFDB.cpp"
#include "../Biff_records/SXFDBType.cpp"
#include "../Biff_records/SxFmla.cpp"
#include "../Biff_records/SXFormula.cpp"
#include "../Biff_records/SXInt.cpp"
#include "../Biff_records/SxName.cpp"
#include "../Biff_records/SxNil.cpp"
#include "../Biff_records/SXNum.cpp"
#include "../Biff_records/SXPair.cpp"
#include "../Biff_records/SXRng.cpp"
#include "../Biff_records/SxIsxoper.cpp"
#include "../Biff_records/IMDATA.cpp"

#include "../Biff_structures/AddinUdf.cpp"
#include "../Biff_structures/AF12Criteria.cpp"
#include "../Biff_structures/AFDOper.cpp"
#include "../Biff_structures/AFDOperRk.cpp"
#include "../Biff_structures/AFDOperStr.cpp"
#include "../Biff_structures/AntiMoniker.cpp"
#include "../Biff_structures/ArrayParsedFormula.cpp"
#include "../Biff_structures/Bes.cpp"
#include "../Biff_structures/BiffString.cpp"
#include "../Biff_structures/BiffStructure.cpp"
#include "../Biff_structures/BookExt_Conditional11.cpp"
#include "../Biff_structures/BookExt_Conditional12.cpp"
#include "../Biff_structures/BorderFillInfo.cpp"
#include "../Biff_structures/BuiltInStyle.cpp"
#include "../Biff_structures/Cell.cpp"
#include "../Biff_structures/CellOffsetResender.cpp"
#include "../Biff_structures/CellParsedFormula.cpp"
#include "../Biff_structures/CellRangeRef.cpp"
#include "../Biff_structures/CellRef.cpp"
#include "../Biff_structures/CellXF.cpp"
#include "../Biff_structures/Cetab.cpp"
#include "../Biff_structures/CFColor.cpp"
#include "../Biff_structures/CFExNonCF12.cpp"
#include "../Biff_structures/CFExTemplateParams.cpp"
#include "../Biff_structures/CFMStateItem.cpp"
#include "../Biff_structures/CFMultistate.cpp"
#include "../Biff_structures/CFParsedFormula.cpp"
#include "../Biff_structures/CFParsedFormulaNoCCE.cpp"
#include "../Biff_structures/CFVO.cpp"
#include "../Biff_structures/CFVOParsedFormula.cpp"
#include "../Biff_structures/ChartNumNillable.cpp"
#include "../Biff_structures/ChartParsedFormula.cpp"
#include "../Biff_structures/CompositeMoniker.cpp"
#include "../Biff_structures/CondFmtStructure.cpp"
#include "../Biff_structures/ControlInfo.cpp"
#include "../Biff_structures/DropDownObjId.cpp"
#include "../Biff_structures/DVParsedFormula.cpp"
#include "../Biff_structures/DXFALC.cpp"
#include "../Biff_structures/DXFBdr.cpp"
#include "../Biff_structures/DXFFntD.cpp"
#include "../Biff_structures/DXFId.cpp"
#include "../Biff_structures/DXFN.cpp"
#include "../Biff_structures/DXFN12.cpp"
#include "../Biff_structures/DXFN12List.cpp"
#include "../Biff_structures/DXFNum.cpp"
#include "../Biff_structures/DXFNumUsr.cpp"
#include "../Biff_structures/DXFPat.cpp"
#include "../Biff_structures/DXFProt.cpp"
#include "../Biff_structures/EncryptionHeader.cpp"
#include "../Biff_structures/EncryptionHeaderFlags.cpp"
#include "../Biff_structures/EncryptionVerifier.cpp"
#include "../Biff_structures/EnhancedProtection.cpp"
#include "../Biff_structures/ExternDdeLinkNoOper.cpp"
#include "../Biff_structures/ExternDocName.cpp"
#include "../Biff_structures/ExternOleDdeLink.cpp"
#include "../Biff_structures/ExtNameParsedFormula.cpp"
#include "../Biff_structures/ExtProp.cpp"
#include "../Biff_structures/ExtPtgArea3D.cpp"
#include "../Biff_structures/ExtPtgAreaErr3D.cpp"
#include "../Biff_structures/ExtPtgErr.cpp"
#include "../Biff_structures/ExtPtgRef3D.cpp"
#include "../Biff_structures/ExtPtgRefErr3D.cpp"
#include "../Biff_structures/ExtRst.cpp"
#include "../Biff_structures/FactoidData.cpp"
#include "../Biff_structures/FactoidType.cpp"
#include "../Biff_structures/Feat11FdaAutoFilter.cpp"
#include "../Biff_structures/Feat11FieldDataItem.cpp"
#include "../Biff_structures/FeatFormulaErr2.cpp"
#include "../Biff_structures/FeatProtection.cpp"
#include "../Biff_structures/FeatSmartTag.cpp"
#include "../Biff_structures/FileMoniker.cpp"
#include "../Biff_structures/FileOffset.cpp"
#include "../Biff_structures/FilePointer.cpp"
#include "../Biff_structures/FixedPoint.cpp"
#include "../Biff_structures/FontIndex.cpp"
#include "../Biff_structures/FormatRun.cpp"
#include "../Biff_structures/FormulaValue.cpp"
#include "../Biff_structures/FrtHeader.cpp"
#include "../Biff_structures/FrtHeaderOld.cpp"
#include "../Biff_structures/FrtRefHeader.cpp"
#include "../Biff_structures/FrtRefHeaderNoGrbit.cpp"
#include "../Biff_structures/FrtRefHeaderU.cpp"
#include "../Biff_structures/Ftab_Cetab.cpp"
#include "../Biff_structures/FtCblsData.cpp"
#include "../Biff_structures/FtCf.cpp"
#include "../Biff_structures/FtCmo.cpp"
#include "../Biff_structures/FtEdoData.cpp"
#include "../Biff_structures/FtGboData.cpp"
#include "../Biff_structures/FtLbsData.cpp"
#include "../Biff_structures/FtMacro.cpp"
#include "../Biff_structures/FtNts.cpp"
#include "../Biff_structures/FtPictFmla.cpp"
#include "../Biff_structures/FtPioGrbit.cpp"
#include "../Biff_structures/FtRboData.cpp"
#include "../Biff_structures/FtSbs.cpp"
#include "../Biff_structures/FullColorExt.cpp"
#include "../Biff_structures/GradStop.cpp"
#include "../Biff_structures/HideObjEnum.cpp"
#include "../Biff_structures/HorzBrk.cpp"
#include "../Biff_structures/HyperlinkMoniker.cpp"
#include "../Biff_structures/HyperlinkObject.cpp"
#include "../Biff_structures/ISSTInf.cpp"
#include "../Biff_structures/ItemMoniker.cpp"
#include "../Biff_structures/LbsDropData.cpp"
#include "../Biff_structures/List12BlockLevel.cpp"
#include "../Biff_structures/List12DisplayName.cpp"
#include "../Biff_structures/List12TableStyleClientInfo.cpp"
#include "../Biff_structures/LongRGB.cpp"
#include "../Biff_structures/MDir.cpp"
#include "../Biff_structures/MDXStrIndex.cpp"
#include "../Biff_structures/MOper.cpp"
#include "../Biff_structures/NameParsedFormula.cpp"
#include "../Biff_structures/NoteRR.cpp"
#include "../Biff_structures/NoteSh.cpp"
#include "../Biff_structures/ObjectParsedFormula.cpp"
#include "../Biff_structures/ObjFmla.cpp"
#include "../Biff_structures/ObjLinkFmla.cpp"
#include "../Biff_structures/PaneType.cpp"
#include "../Biff_structures/ParsedFormula.cpp"
#include "../Biff_structures/PhRuns.cpp"
#include "../Biff_structures/Phs.cpp"
#include "../Biff_structures/PictFmlaEmbedInfo.cpp"
#include "../Biff_structures/PictFmlaKey.cpp"
#include "../Biff_structures/PropertyBag.cpp"
#include "../Biff_structures/PropertyBagStore.cpp"
#include "../Biff_structures/Ptg.cpp"
#include "../Biff_structures/PtgArea.cpp"
#include "../Biff_structures/PtgArea3d.cpp"
#include "../Biff_structures/PtgAreaErr.cpp"
#include "../Biff_structures/PtgAreaErr3d.cpp"
#include "../Biff_structures/PtgAreaN.cpp"
#include "../Biff_structures/PtgArray.cpp"
#include "../Biff_structures/PtgAttrBaxcel.cpp"
#include "../Biff_structures/PtgAttrChoose.cpp"
#include "../Biff_structures/PtgAttrGoto.cpp"
#include "../Biff_structures/PtgAttrIf.cpp"
#include "../Biff_structures/PtgAttrIfError.cpp"
#include "../Biff_structures/PtgAttrSemi.cpp"
#include "../Biff_structures/PtgAttrSpace.cpp"
#include "../Biff_structures/PtgAttrSpaceSemi.cpp"
#include "../Biff_structures/PtgAttrSum.cpp"
#include "../Biff_structures/PtgBool.cpp"
#include "../Biff_structures/PtgElfCol.cpp"
#include "../Biff_structures/PtgElfColS.cpp"
#include "../Biff_structures/PtgElfColSV.cpp"
#include "../Biff_structures/PtgElfColV.cpp"
#include "../Biff_structures/PtgElfLel.cpp"
#include "../Biff_structures/PtgElfRadical.cpp"
#include "../Biff_structures/PtgElfRadicalLel.cpp"
#include "../Biff_structures/PtgElfRadicalS.cpp"
#include "../Biff_structures/PtgElfRw.cpp"
#include "../Biff_structures/PtgElfRwV.cpp"
#include "../Biff_structures/PtgErr.cpp"
#include "../Biff_structures/PtgExp.cpp"
#include "../Biff_structures/PtgExtraArray.cpp"
#include "../Biff_structures/PtgExtraCol.cpp"
#include "../Biff_structures/PtgExtraList.cpp"
#include "../Biff_structures/PtgExtraElf.cpp"
#include "../Biff_structures/PtgExtraMem.cpp"
#include "../Biff_structures/PtgFactory.cpp"
#include "../Biff_structures/PtgFunc.cpp"
#include "../Biff_structures/PtgFuncVar.cpp"
#include "../Biff_structures/PtgInt.cpp"
#include "../Biff_structures/PtgList.cpp"
#include "../Biff_structures/PtgMemArea.cpp"
#include "../Biff_structures/PtgMemAreaN.cpp"
#include "../Biff_structures/PtgMemErr.cpp"
#include "../Biff_structures/PtgMemFunc.cpp"
#include "../Biff_structures/PtgMemNoMem.cpp"
#include "../Biff_structures/PtgMemNoMemN.cpp"
#include "../Biff_structures/PtgMissArg.cpp"
#include "../Biff_structures/PtgName.cpp"
#include "../Biff_structures/PtgNameX.cpp"
#include "../Biff_structures/PtgNum.cpp"
#include "../Biff_structures/PtgParam.cpp"
#include "../Biff_structures/PtgParen.cpp"
#include "../Biff_structures/PtgRef.cpp"
#include "../Biff_structures/PtgRef3d.cpp"
#include "../Biff_structures/PtgRefErr.cpp"
#include "../Biff_structures/PtgRefErr3d.cpp"
#include "../Biff_structures/PtgRefN.cpp"
#include "../Biff_structures/PtgStr.cpp"
#include "../Biff_structures/PtgSxName.cpp"
#include "../Biff_structures/PtgTbl.cpp"
#include "../Biff_structures/RC4CryptoAPIEncryptionHeader.cpp"
#include "../Biff_structures/RC4EncryptionHeader.cpp"
#include "../Biff_structures/RevExtern.cpp"
#include "../Biff_structures/RevItab.cpp"
#include "../Biff_structures/RevLblName.cpp"
#include "../Biff_structures/RevName.cpp"
#include "../Biff_structures/RevNamePly.cpp"
#include "../Biff_structures/RevNameTabid.cpp"
#include "../Biff_structures/RgbExtra.cpp"
#include "../Biff_structures/Rgce.cpp"
#include "../Biff_structures/RkRec.cpp"
#include "../Biff_structures/RPHSSub.cpp"
#include "../Biff_structures/RRD.cpp"
#include "../Biff_structures/Run.cpp"
#include "../Biff_structures/SDContainer.cpp"
#include "../Biff_structures/SecurityDescriptor.cpp"
#include "../Biff_structures/SerAr.cpp"
#include "../Biff_structures/SerBool.cpp"
#include "../Biff_structures/SerErr.cpp"
#include "../Biff_structures/SerNil.cpp"
#include "../Biff_structures/SerNum.cpp"
#include "../Biff_structures/SerStr.cpp"
#include "../Biff_structures/SharedParsedFormula.cpp"
#include "../Biff_structures/SheetExtOptional.cpp"
#include "../Biff_structures/SheetId.cpp"
#include "../Biff_structures/SortCond12.cpp"
#include "../Biff_structures/SqRef.cpp"
#include "../Biff_structures/SqRefU.cpp"
#include "../Biff_structures/StringPtgParser.cpp"
#include "../Biff_structures/Stxp.cpp"
#include "../Biff_structures/StyleXF.cpp"
#include "../Biff_structures/SyntaxPtg.cpp"
#include "../Biff_structures/TableFeatureType.cpp"
#include "../Biff_structures/TxOLastRun.cpp"
#include "../Biff_structures/TxORuns.cpp"
#include "../Biff_structures/URICreateFlags.cpp"
#include "../Biff_structures/URLMoniker.cpp"
#include "../Biff_structures/VertBrk.cpp"
#include "../Biff_structures/XFExtGradient.cpp"
#include "../Biff_structures/XFExtNoFRT.cpp"
#include "../Biff_structures/XFProp.cpp"
#include "../Biff_structures/XFPropBorder.cpp"
#include "../Biff_structures/XFPropColor.cpp"
#include "../Biff_structures/XFPropGradient.cpp"
#include "../Biff_structures/XFPropGradientStop.cpp"
#include "../Biff_structures/XFProps.cpp"
#include "../Biff_structures/XLUnicodeRichExtendedString.cpp"
#include "../Biff_structures/XORObfuscation.cpp"
#include "../Biff_structures/XTI.cpp"
#include "../Biff_structures/ODRAW/MSOCR.cpp"
#include "../Biff_structures/ODRAW/MSOSHADECOLOR.cpp"
#include "../Biff_structures/ODRAW/OfficeArtBlip.cpp"
#include "../Biff_structures/ODRAW/OfficeArtBStoreContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtBStoreContainerFileBlock.cpp"
#include "../Biff_structures/ODRAW/OfficeArtClientAnchorChart.cpp"
#include "../Biff_structures/ODRAW/OfficeArtClientAnchorHF.cpp"
#include "../Biff_structures/ODRAW/OfficeArtClientAnchorSheet.cpp"
#include "../Biff_structures/ODRAW/OfficeArtColorMRUContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtCOLORREF.cpp"
#include "../Biff_structures/ODRAW/OfficeArtContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtDgContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFDG.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFDGGBlock.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFOPT.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFOPTE.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFRIT.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFRITContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFSP.cpp"
#include "../Biff_structures/ODRAW/OfficeArtFSPGR.cpp"
#include "../Biff_structures/ODRAW/OfficeArtIDCL.cpp"
#include "../Biff_structures/ODRAW/OfficeArtMetafileHeader.cpp"
#include "../Biff_structures/ODRAW/OfficeArtRecord.cpp"
#include "../Biff_structures/ODRAW/OfficeArtRecordHeader.cpp"
#include "../Biff_structures/ODRAW/OfficeArtRGFOPTE.cpp"
#include "../Biff_structures/ODRAW/OfficeArtSplitMenuColorContainer.cpp"
#include "../Biff_structures/ODRAW/OfficeArtTertiaryFOPT.cpp"
#include "../Biff_structures/ODRAW/SimpleOfficeArtContainers.cpp"
#include "../Biff_structures/SharedProperty.cpp"
#include "../Biff_structures/AFDOperBoolErr.cpp"
#include "../Biff_structures/AFDOperXNum.cpp"
#include "../Biff_structures/PivotParsedFormula.cpp"
#include "../Biff_structures/ListParsedFormula.cpp"
#include "../Biff_structures/CachedDiskHeader.cpp"
#include "../Biff_structures/Feat11Fmla.cpp"
#include "../Biff_structures/Feat11WSSListInfo.cpp"
#include "../Biff_structures/Feat11XMap.cpp"
#include "../Biff_structures/AF12CellIcon.cpp"
#include "../Biff_structures/CFDatabar.cpp"
#include "../Biff_structures/CFGradient.cpp"
#include "../Biff_structures/SxAxis.cpp"
#include "../Biff_structures/SXVIFlags.cpp"
#include "../Biff_structures/HiddenMemberSet.cpp"
#include "../Biff_structures/ConnGrbitDbtAdo.cpp"
#include "../Biff_structures/ConnGrbitDbtOledb.cpp"
#include "../Biff_structures/ConnGrbitDbtWeb.cpp"
#include "../Biff_structures/DConnConnectionOleDb.cpp"
#include "../Biff_structures/DConnConnectionWeb.cpp"
#include "../Biff_structures/DConnId.cpp"
#include "../Biff_structures/DConnParamBindingValType.cpp"
#include "../Biff_structures/DConnParameter.cpp"
#include "../Biff_structures/DConnStringSequence.cpp"
#include "../Biff_structures/TxtWf.cpp"
#include "../Biff_structures/Xnum.cpp"
#include "../Biff_structures/PBT.cpp"
#include "../Biff_structures/FontInfo.cpp"

#include "../Biff_unions/AI.cpp"
#include "../Biff_unions/ATTACHEDLABEL_bu.cpp"
#include "../Biff_unions/AUTOFILTER_bu.cpp"
#include "../Biff_unions/AXES.cpp"
#include "../Biff_unions/AXISPARENT_bu.cpp"
#include "../Biff_unions/AXM.cpp"
#include "../Biff_unions/AXS.cpp"
#include "../Biff_unions/BACKGROUND.cpp"
#include "../Biff_unions/BIGNAME_bu.cpp"
#include "../Biff_unions/BUNDLESHEET.cpp"
#include "../Biff_unions/CELL_bu.cpp"
#include "../Biff_unions/CELLTABLE.cpp"
#include "../Biff_unions/CHART_bu.cpp"
#include "../Biff_unions/CHARTFOMATS.cpp"
#include "../Biff_unions/COLUMNS.cpp"
#include "../Biff_unions/CONDFMT_bu.cpp"
#include "../Biff_unions/CONDFMT12_bu.cpp"
#include "../Biff_unions/CONDFMTS.cpp"
#include "../Biff_unions/CRT.cpp"
#include "../Biff_unions/CRTMLFRT_bu.cpp"
#include "../Biff_unions/CUSTOMVIEW.cpp"
#include "../Biff_unions/DAT_bu.cpp"
#include "../Biff_unions/DBQUERY.cpp"
#include "../Biff_unions/DBQUERYEXT_bu.cpp"
#include "../Biff_unions/DCON_bu.cpp"
#include "../Biff_unions/DFTTEXT.cpp"
#include "../Biff_unions/DOCROUTE_bu.cpp"
#include "../Biff_unions/DREF.cpp"
#include "../Biff_unions/DROPBAR_bu.cpp"
#include "../Biff_unions/DVAL_bu.cpp"
#include "../Biff_unions/DVAXIS.cpp"
#include "../Biff_unions/FEAT_bu.cpp"
#include "../Biff_unions/FEAT11.cpp"
#include "../Biff_unions/FNGROUPS.cpp"
#include "../Biff_unions/FONTLIST.cpp"
#include "../Biff_unions/FORMATTING.cpp"
#include "../Biff_unions/FORMULA_bu.cpp"
#include "../Biff_unions/FRAME_bu.cpp"
#include "../Biff_unions/GELFRAME_bu.cpp"
#include "../Biff_unions/GLOBALS.cpp"
#include "../Biff_unions/HLINK_bu.cpp"
#include "../Biff_unions/INTERFACE.cpp"
#include "../Biff_unions/IVAXIS.cpp"
#include "../Biff_unions/LBL_bu.cpp"
#include "../Biff_unions/LD.cpp"
#include "../Biff_unions/MACROSORTANDFILTER.cpp"
#include "../Biff_unions/MDBLOCK.cpp"
#include "../Biff_unions/MDTINFO_bu.cpp"
#include "../Biff_unions/MDXSTR_bu.cpp"
#include "../Biff_unions/MDXTUPLESET.cpp"
#include "../Biff_unions/METADATA.cpp"
#include "../Biff_unions/MSODRAWINGGROUP_bu.cpp"
#include "../Biff_unions/OBJ_bu.cpp"
#include "../Biff_unions/OBJECTS.cpp"
#include "../Biff_unions/PAGESETUP.cpp"
#include "../Biff_unions/PHONETICINFO_bu.cpp"
#include "../Biff_unions/PICF_bu.cpp"
#include "../Biff_unions/PIVOTADDL.cpp"
#include "../Biff_unions/PIVOTCACHEDEFINITION.cpp"
#include "../Biff_unions/PIVOTCORE.cpp"
#include "../Biff_unions/PIVOTEX.cpp"
#include "../Biff_unions/PIVOTFORMAT.cpp"
#include "../Biff_unions/PIVOTFRT.cpp"
#include "../Biff_unions/PIVOTFRT9.cpp"
#include "../Biff_unions/PIVOTIVD.cpp"
#include "../Biff_unions/PIVOTLI.cpp"
#include "../Biff_unions/PIVOTPI.cpp"
#include "../Biff_unions/PIVOTRULE.cpp"
#include "../Biff_unions/PIVOTSELECT.cpp"
#include "../Biff_unions/PIVOTTH.cpp"
#include "../Biff_unions/PIVOTVD.cpp"
#include "../Biff_unions/PIVOTVDTEX.cpp"
#include "../Biff_unions/PIVOTVIEW.cpp"
#include "../Biff_unions/PIVOTVIEWEX.cpp"
#include "../Biff_unions/PRFILTER.cpp"
#include "../Biff_unions/PROTECTION.cpp"
#include "../Biff_unions/PROTECTION_COMMON.cpp"
#include "../Biff_unions/QSIR_bu.cpp"
#include "../Biff_unions/QUERYTABLE.cpp"
#include "../Biff_unions/RECORD12.cpp"
#include "../Biff_unions/RTD.cpp"
#include "../Biff_unions/SCENARIOS.cpp"
#include "../Biff_unions/SERIESAXIS.cpp"
#include "../Biff_unions/SERIESDATA.cpp"
#include "../Biff_unions/SERIESFORMAT.cpp"
#include "../Biff_unions/SHAPEPROPS.cpp"
#include "../Biff_unions/SHAREDSTRINGS.cpp"
#include "../Biff_unions/SHFMLA_SET.cpp"
#include "../Biff_unions/SORT_bu.cpp"
#include "../Biff_unions/SORTANDFILTER.cpp"
#include "../Biff_unions/SORTDATA12.cpp"
#include "../Biff_unions/SS.cpp"
#include "../Biff_unions/STYLES.cpp"
#include "../Biff_unions/SUB.cpp"
#include "../Biff_unions/SUPBOOK_bu.cpp"
#include "../Biff_unions/SXADDLAUTOSORT.cpp"
#include "../Biff_unions/SXADDLCACHE.cpp"
#include "../Biff_unions/SXADDLCACHE12.cpp"
#include "../Biff_unions/SXADDLCACHEFIELD.cpp"
#include "../Biff_unions/SXADDLCACHEITEM.cpp"
#include "../Biff_unions/SXADDLCALCMEMBER.cpp"
#include "../Biff_unions/SXADDLCONDFMT.cpp"
#include "../Biff_unions/SXADDLCONDFMTS.cpp"
#include "../Biff_unions/SXADDLDBQUERY.cpp"
#include "../Biff_unions/SXADDLFIELD.cpp"
#include "../Biff_unions/SXADDLFIELD12.cpp"
#include "../Biff_unions/SXADDLGROUP.cpp"
#include "../Biff_unions/SXADDLGRPLEVEL.cpp"
#include "../Biff_unions/SXADDLHIERARCHY.cpp"
#include "../Biff_unions/SXADDLQSI.cpp"
#include "../Biff_unions/SXADDLSXDH.cpp"
#include "../Biff_unions/SXADDLSXFILT.cpp"
#include "../Biff_unions/SXADDLSXFILTER12.cpp"
#include "../Biff_unions/SXADDLSXFILTERS12.cpp"
#include "../Biff_unions/SXADDLSXMG.cpp"
#include "../Biff_unions/SXADDLSXMGS.cpp"
#include "../Biff_unions/SXADDLSXRULE.cpp"
#include "../Biff_unions/SXSRC.cpp"
#include "../Biff_unions/SXTBL_bu.cpp"
#include "../Biff_unions/TABLESTYLES_bu.cpp"
#include "../Biff_unions/TEXTOBJECT.cpp"
#include "../Biff_unions/TEXTPROPS.cpp"
#include "../Biff_unions/THEME_bu.cpp"
#include "../Biff_unions/UNKNOWNFRT.cpp"
#include "../Biff_unions/WINDOW.cpp"
#include "../Biff_unions/XFS.cpp"
#include "../Biff_unions/DBB.cpp"
#include "../Biff_unions/FDB.cpp"
#include "../Biff_unions/PIVOTCACHE.cpp"
#include "../Biff_unions/SXFMLA_bu.cpp"
#include "../Biff_unions/SXFORMULA_bu.cpp"
#include "../Biff_unions/SXOPER.cpp"
#include "../Biff_unions/SXRANGE.cpp"
#include "../Biff_unions/IMDATAOBJECT.cpp"

#include "../../../Common/SummaryInformation/PropertyFactory.cpp"
#include "../../../Common/SummaryInformation/PropertySet.cpp"
#include "../../../Common/SummaryInformation/PropertySetStream.cpp"
#include "../../../Common/SummaryInformation/CodePageOle.cpp"

#include "../AnyObject.cpp"
#include "../AnySubstream.cpp"
#include "../BinProcessor.cpp"
#include "../ChartSheetSubstream.cpp"
#include "../CompositeObject.cpp"
#include "../EncryptionStream.cpp"
#include "../GlobalsSubstream.cpp"
#include "../GlobalWorkbookInfo.cpp"
#include "../MacroSheetSubstream.cpp"
#include "../WorkbookStreamObject.cpp"
#include "../WorksheetSubstream.cpp"
#include "../CommonSubstream.cpp"
