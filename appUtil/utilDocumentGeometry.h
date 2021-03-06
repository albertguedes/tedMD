/************************************************************************/
/*									*/
/*  Various definitions relating to document geometry.			*/
/*									*/
/************************************************************************/

#   ifndef	UTIL_DOCUMENT_GEOMETRY_H
#   define	UTIL_DOCUMENT_GEOMETRY_H

#   include	"utilPropMask.h"
#   include	"geo2DInteger.h"

typedef struct DocumentGeometry
    {
    int			dgPageWideTwips;
    int			dgPageHighTwips;

    int			dgLeftMarginTwips;
    int			dgTopMarginTwips;
    int			dgRightMarginTwips;
    int			dgBottomMarginTwips;

    int			dgHeaderPositionTwips;
    int			dgFooterPositionTwips;

    int			dgGutterTwips;
    unsigned char	dgMirrorMargins;
    } DocumentGeometry;

/************************************************************************/
/*									*/
/*  Update masks for document geometry.					*/
/*									*/
/*  NOTE: This range is continued in Ted/docBuf.h for the section and	*/
/*	document properties. Adding a bit here may make it necessary to	*/
/*	shift the masks there as well.					*/
/*									*/
/************************************************************************/

typedef enum GeometryProperty
    {
    DGprop_NONE= -1,

    DGpropPAGE_WIDTH= 0,
    DGpropPAGE_HEIGHT,
    DGpropLEFT_MARGIN,
    DGpropRIGHT_MARGIN,
    DGpropTOP_MARGIN,
    DGpropBOTTOM_MARGIN,
    DGpropHEADER_POSITION,
    DGpropFOOTER_POSITION,
    DGpropGUTTER,
    DGpropMARGMIR,

    DGprop_COUNT
    } GeometryProperty;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

extern void utilInitDocumentGeometry(	DocumentGeometry *	dg );

extern void utilUpdDocumentGeometry(
				PropertyMask *			dpDoneMask,
				DocumentGeometry *		dgTo,
				const PropertyMask *		dgSetMask,
				const DocumentGeometry *	dgSet );

extern void utilDocumentGeometryGetBodyRect(
				DocumentRectangle *		dr,
				const DocumentGeometry *	dg );

extern void utilDocumentGeometryGetHeaderRect(
				DocumentRectangle *		dr,
				const DocumentGeometry *	dg );

extern void utilDocumentGeometryGetFooterRect(
				DocumentRectangle *		dr,
				const DocumentGeometry *	dg );

extern void utilDocumentGeometryGetPageBoundingBox(
				DocumentRectangle *		dr,
				const DocumentGeometry *	dg,
				int				hasHeader,
				int				hasFooter );

extern void utilOverridePaperSize(
				DocumentGeometry *		dgTo,
				const DocumentGeometry *	dgFrom );

#   endif
