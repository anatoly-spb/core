﻿/*
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
#pragma once

namespace cpdoccore { 
//namespace odf_reader {

enum ElementType
{
    typeNone = 0,
    type_AbstractXml,

    typeTextText = 1000,
    typeTextS,
    typeTextTab,
    typeTextLineBreak,
    typeTextBookmark,
    typeTextBookmarkStart,
    typeTextBookmarkEnd,
    typeTextBookmarkRef,
    typeTextReferenceMark,
    typeTextReferenceMarkStart,
    typeTextReferenceMarkEnd,
	typeTextReferenceRef,

	typeFieldFieldmarkStart,
	typeFieldFieldmarkEnd,
	typeFieldFieldmark,
	typeFieldParam,

    typeTextSpan,
    typeTextA,
    typeTextNote,
    typeTextNoteCitation,
    typeTextNoteBody,
    typeTextRuby,
    typeTextRubyBase,
    typeTextRubyText,
    typeTextOfficeAnnotation,
    typeTextTitle,
	typeTextChapter,
	typeTextSubject,
    typeTextPlaceholder,
    typeTextPageNumber,
    typeTextPageCount,
    typeTextDate,
    typeTextModificationDate,
    typeTextTime,
    typeTextModificationTime,
    typeTextFileName,
    typeTextSheetName,
    typeTextTemplateName,
	typeTextDropDown,
	typeTextLabel,
	typeTextSenderCompany,
	typeTextSenderFirstname,
	typeTextSenderLastname,
	typeTextSenderTitle,
	typeTextSenderPosition,
	typeTextSenderEmail,
	typeTextSenderFax,
	typeTextSenderPhonePrivate,
	typeTextSenderPhoneWork,
	typeTextSenderStreet,
	typeTextSenderCity,
	typeTextSenderCountry,
	typeTextSenderPostalCode,
	typeTextSenderStateOrProvince,
	typeTextAuthorInitials,
	typeTextAuthorName,

    typeTextSequenceDecls,
    typeTextSequenceDecl,
    typeTextSequence,
	typeTextSequenceRef,

	typeTextHiddenParagraph,
	typeTextHiddenText,

	typePresentationFooter,
	typePresentationDateTime,

	typeDcCreator,
	typeDcDate,
	typeDcDescription,
	typeDcSubject,
	typeDcTitle,

	typeDrawA,

    typeTextH,
    typeTextP,

    typeTextList,
    typeTextListItem,
    typeTextListHeader,
    typeTextNumber,
    typeTextSoftPageBreak,
    typeTextSection,
    typeTextSectionSource,
    typeTextIndexTitle,
    typeTextIndexBody,
    typeTextNumberedParagraph, 
	typeTextExpression,    

	typeTextCommonEntryTemplate,

    typeTextTableOfContent,
    typeTextTableOfContentSource,
	typeTextTableOfContentEntryTemplate,

	typeTextIndexEntryText,
	typeTextIndexEntryTabStop,
	typeTextIndexEntrySpan,
	typeTextIndexEntryPageNumber,
	typeTextIndexEntryLinkStart,
	typeTextIndexEntryLinkEnd,
	typeTextIndexEntryChapter,
	typeTextIndexEntryBibliography,
    
	typeTextIllustrationIndex,
    typeTextIllustrationIndexSource,
     typeTextIllustrationIndexEntryTemplate,
  
	typeTextTableIndex,
    typeTextTableIndexSource,
 	typeTextTableIndexEntryTemplate,
   
	typeTextObjectIndex,
    typeTextObjectIndexSource,
	typeTextObjectIndexEntryTemplate,
  
	typeTextUserIndex,
    typeTextUserIndexSource,
	typeTextUserIndexEntryTemplate,
    
	typeTextAlphabeticalIndex,
    typeTextAlphabeticalIndexSource,
	typeTextAlphabeticalIndexEntryTemplate,
  
	typeTextBibliography,
    typeTextBibliographySource, 
	typeTextBibliographyEntryTemplate,

	typeTextBibliographyMark,

	typeTextAlphabeticalIndexAutoMarkFile,
	typeTextAlphabeticalIndexMarkStart,
	typeTextAlphabeticalIndexMarkEnd,
	typeTextAlphabeticalIndexMark,

	typeTextTocMarkStart,
	typeTextTocMarkEnd,
	typeTextTocMark,

	typeTextUserIndexMarkStart,
	typeTextUserIndexMarkEnd,
	typeTextUserIndexMark,

	typeTextIndexSourceStyles,
	typeTextIndexSourceStyle,

	typeTextVariableInput,
	typeTextVariableGet,
	typeTextVariableSet,
	typeTextVariableDecl,
	typeTextVariableDecls,

	typeTextUserFieldDecls,
	typeTextUserFieldDecl,
	typeTextUserFieldGet,
	typeTextUserFieldSet,
	typeTextUserFieldInput,

	typeTextUserDefined,

	typeTextTrackedChanges,
	typeTextChangedRegion,
	typeTextChangeStart,
	typeTextChangeEnd,
	typeTextChange,
	typeOfficeChangeInfo,
	
	typeTextUnknownChange,
	typeTextDeletion,
	typeTextFormatChange,
	typeTextInsertion,

	typeTextMeta,
	typeTextMetaField,

	typeTextTextInput,

	typeShape,
    typeChangeMarks,

    typeOfficeAutomaticStyles,
    typeOfficeMasterStyles,
    typeStyleMasterPage,
	typeStyleHandoutMasterPage,
    typeOfficeStyles,
    typeStyleDefaultStyle,
    typeStyleStyle,
    typeTextListStyle,
    typeTextListLevelStyleNumber,
    typeTextListLevelStyleBullet,
	typeTextListLevelStyleImage,
	typeStyleListLevelProperties,
    typeStyleListLevelLabelAlignment,

    typeStyleTabStop,
    typeStyleTabStops,
    typeStyleDropCap,
    typeStyleBackgroundImage,
    typeStyleTextProperties,
    typeStyleParagraphProperties,
    typeStyleTableProperties,
    typeStyleTableColumnProperties,
    typeStyleTableRowProperties,
    typeStyleTableCellProperties,
    typeStyleHeader,
    typeStyleFooter,
    typeStyleHeaderFirst,
    typeStyleFooterFirst,
	typeStyleHeaderLeft,
    typeStyleFooterLeft,
    typeStyleFootnoteSep,

    typeStyleSectionProperties,
    typeStyleHeaderStyle,
    typeStyleFooterStyle,
	typeStyleHeaderFooterProperties,

	typeStylePresentationSound,
	typeStylePresentationPageLayout,
	typeStylePresentationPlaceholder,
	typeStyleDrawingPageProperties,

    typeStyleColumns,
    typeStyleColumn,
    typeStyleColumnSep,

    typeStylePageLayout,
    typeStyleMap,

	typeTableTemplate,
	typeTableTemplateElement,
	typeTableBodyTemplate,
	typeTableFirstRowTemplate,
	typeTableLastRowTemplate,
	typeTableFirstColumnTemplate,
	typeTableLastColumnTemplate,
	typeTableOddColumnsTemplate,
	typeTableOddRowsTemplate,

	typeTextIndexTitleTemplate,

    typeTextNotesConfiguration,

    typeStyleFontFace,

    typeSvgDesc,
    typeSvgFontFaceUri,
    typeSvgFontFaceFormat,
    typeSvgFontFaceName,
    typeSvgDefinitionSrc,
    typeOfficeFontFaceDecls,

    typeOfficeBinaryData,

    typeTableNamedExpressions,
    typeTableNamedExpression,
    typeTableNamedRange,
	typeTableDatabaseRanges,
	typeTableDatabaseRange,
	typeTableSort,
	typeTableSortBy,
	typeTableCalculationSettings,
    typeTableNullDate,
    typeTableShapes,
	typeTableContentValidation,
	typeTableContentValidations,
	typeTableHelpMassage,
	typeTableErrorMassage,
	typeTableErrorMacro,

	typeTableFilter,
	typeTableFilterAnd,
	typeTableFilterOr,
	typeTableFilterCondition,
	typeTableFilterSetItem,

	typeTableTable,
    typeTableTableColumn,
    typeTableTableColumns,
    typeTableTableHeaderColumns,
    typeTableTableColumnGroup,
    typeTableTableRow,
    typeTableTableCell,
    typeTableCoveredTableCell,
    typeTableTableRows,
    typeTableTableHeaderRows,
    typeTableTableRowGroup,
	typeTableTableRowNoGroup,
    typeTableTableSource,
	typeTableTableProtection,

	typeTableDataPilotTables,
	typeTableDataPilotTable,
	typeTableDataPilotField,
	typeTableDataPilotFieldReference,
	typeTableDatabaseSourceTable,
	typeTableDatabaseSourceQuery,
	typeTableDatabaseSourceSql,
	typeTableSourceCellRange,
	typeTableSourceCellRanges,
	typeTableSourceService,
	typeTableDataPilotGrandTotal,
	typeTableDataPilotSubtotals,
	typeTableDataPilotSubtotal,
	typeTableDataPilotGroupMember,
	typeTableDataPilotMember,
	typeTableDataPilotMembers,
	typeTableDataPilotGroup,
	typeTableDataPilotGroups,
	typeTableDataPilotLevel,
	typeTableDataSortInfo,
	typeTableDataDisplayInfo,
	typeTableDataLayoutInfo,
        
    typeOfficeBody,
    typeOfficeText,
    typeOfficeDocument,
    typeOfficeDocumentContent,
    typeOfficeDocumentStyles,
    typeOfficeDocumentMeta,
    typeOfficeDocumentSettings,

	typeMathElement,
	typeMath,
	typeMathSemantics,
	typeMathAnnotation,
	typeMathAnnotationXml,
	typeMN,
	typeMI,
	typeMS,
	typeMSpace,
	typeMO,
	typeMText,
	typeMGlyph,
	typeMSqrt,
	typeMRoot,
	typeMFrac,
	typeMRow,
	typeMStyle,
	typeMEnClose,
	typeMFenced,
	typeMPadded,
	typeMError,
	typeMPhantom,
	typeMTable,
	typeMAlignMark,
	typeMAlignGroup,
	typeMTd,
	typeMLabelEdTr,
	typeMTr,
	typeMSub,
	typeMSup,
	typeMSubSup,
	typeMNone,
	typeMPreScripts,
	typeMMultiScripts,
	typeMUnderOver,
	typeMOver,
	typeMUnder,
	typeMStack,
	typeMSRow,
	typeMSLine,
	typeMSCarry,
	typeMSCarries,
	typeMSGroup,
	typeMSLongDiv,

	typeManifest,
	typeManifestEntry,
	typeManifestEncryptionData,

	typeManifestAlgorithm,
	typeManifestStartKeyGeneration,
	typeManifestKeyDerivation,

	typeOfficeSettings,
	typeOfficeSettingsConfigItemSet,
	typeOfficeSettingsConfigItem,
	typeOfficeSettingsConfigItemMapIndexed,
	typeOfficeSettingsConfigItemMapNamed,
  	typeOfficeSettingsConfigItemMapEntry,

	typeOfficeMeta,
	typeOfficeMetaUserDefined,
	typeOfficeMetaDocumentStatistic,
	typeOfficeMetaGenerator,
	typeOfficeMetaCreationDate,
	typeOfficeMetaKeyword,
	typeOfficeMetaEditingCycles,
	typeOfficeMetaEditingDuration,

	typeDrawBase,
 	typeDrawG,
	typeDrawFrame,
    typeDrawImage,
    typeDrawTextBox,
    typeDrawObject,
    typeDrawObjectOle,
 	typeDrawChart,
 	typeDrawParam,
 	typeDrawPlugin,

	typeDrawShape,

	typeDrawRect,
	typeDrawEllipse,
	typeDrawLine,
	typeDrawPolygon,
	typeDrawContourPolygon,
	typeDrawPolyline,
	typeDrawRegularPolyline,
	typeDrawPath,
	typeDrawContourPath,
	typeDrawCircle,
	typeDrawg,
	typeDrawPageThumbnail,
	typeDrawMeasure,
	typeDrawCaption,
	typeDrawConnector,
	typeDrawControl,
	typeDraw3dScene,
	typeDrawCustomShape,
	typeDrawHandle,
	typeDrawEquation,
	typeDrawEnhancedGeometry,
	typeDrawGluePoint,

	typeDr3dScene,
	typeDr3dLight,
	typeDr3dExtrude,
	typeDr3dCube,
	typeDr3dRotate,
	typeDr3dSphere,

	typeOfficeForms,
	typeFormForm,
	typeFormProperties,
	typeFormProperty,
	typeFormListProperty,
	typeFormListValue,
	typeFormElement,
	typeFormButton,
	typeFormCheckbox,
	typeFormText,
	typeFormCombobox,
	typeFormListbox,
	typeFormConnectionResource,
	typeFormDate,
	typeFormFile,
	typeFormFixedText,
	typeFormFormattedText, 
	typeFormFrame,
	typeFormGenericControl,
	typeFormGrid,
	typeFormHidden,
	typeFormImage,
	typeFormImageFrame, 
	typeFormNumber,
	typeFormPassword, 
	typeFormRadio,
	typeFormTextarea,
	typeFormTime,
	typeFormValueRange,
	typeFormItem,
	typeFormOption,

	typeDrawPage,    
	typePresentationFooterDecl,
	typePresentationDateTimeDecl,
	typePresentationNotes,

	typeAnimPar,
	typeAnimSeq,
	typeAnimTransitionFilter,
	typeAnimAudio,
	typeAnimCommand,
	typeAnimIterate,

	typeStyleGraphicPropertis,
	typeStyleDrawGradient,
	typeStyleDrawFillImage,
	typeStyleDrawHatch,
	typeStyleDrawMarker,
	typeStyleDrawOpacity,
	typeStyleDrawStrokeDash,
	typeStyleDrawLayer,
	typeStyleDrawLayerSet,

	typeOfficeSpreadsheet,
	typeOfficeAnnotation,
	typeOfficeAnnotationStart,
	typeOfficeAnnotationEnd,
	typeStyleRegionLeft,
	typeOfficeScripts,
	typeOfficeScript,
	typeOfficePresentation,
	typeOfficeChart,
	typeOfficeEventListeners,
  
	typePresentationEventListener,	

	typeScriptEventListener,

    typeNumberNumberStyle,
    typeNumberDataStyle,
    typeNumberText,
    typeNumberNumber,
    typeNumberEmbeddedText,
    typeNumberScientificNumber,
    typeNumberFraction,
    typeNumberCurrencyStyle,
    typeNumberCurrencySymbol,
    typeNumberTextContent,
    typeNumberTextStyle,
    typeNumberPercentageStyle,
    typeNumberTimeStyle,
    typeNumberDay,
    typeNumberMonth,
    typeNumberYear,
    typeNumberDayOfWeek,
    typeNumberQuarter,
    typeNumberHours,
    typeNumberMinutes,
    typeNumberSeconds,
    typeNumberAmPm,

    typeChartChart,
    typeChartTitle,
    typeChartSubtitle,
    typeChartFooter,
    typeChartLegend,
    typeChartPlotArea,
    typeChartWall,
    typeChartFloor,
    typeChartAxis,
    typeChartGrid,
    typeChartCategories,
    typeChartSeries,
    typeChartDomain,
    typeChartDataPoint,
    typeChartErrorIndicator,
    typeChartMeanValue,
    typeChartStockGainMarker,
    typeChartStockLossMarker,
    typeChartStockRangeLine,
	typeChartRegressionCurve,
	typeChartEquation,

	typeStyleRegionCenter,
    typeStyleRegionRight,
	typeStyleChartProperties,

	typeCalcextColorScaleEntry,
	typeCalcextFormattingEntry,
	typeCalcextIconSet,
	typeCalcextDataBar,
	typeCalcextColorScale,
	typeCalcextDateIs,
	typeCalcextCondition,
	typeCalcextConditionalFormat,
	typeCalcextConditionalFormats

};


//}
}

