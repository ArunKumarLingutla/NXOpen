#pragma once
#ifndef HEADER_HPP
#define HEADER_HPP

// NXOpen C API

#include <uf_route.h>;

#include <uf.h>

#include <uf_assem.h>

#include <uf_assem_types.h>

#include <uf_attr.h>

#include <uf_curve.h>

#include <uf_csys.h>

#include <uf_defs.h>

#include <uf_disp_types.h>

#include <uf_drf.h>

#include <uf_eval.h>

#include <uf_exit.h>

#include <uf_group.h>

#include <uf_modl.h>

#include <uf_modl_curves.h>

#include <uf_modl_freeform.h>

#include <uf_mtx.h>

#include <uf_obj.h>

#include <uf_part.h>

#include <uf_point.h>

#include <uf_ps.h>

#include <uf_sf.h>

#include <uf_sf_element_check.h>

#include <uf_so.h>

#include <uf_trns.h>

#include <uf_ui.h>

#include <uf_undo.h>

#include <uf_vec.h>

#include <uf_view.h>

#include <stdarg.h>

#include <uf_evalsf.h>

#include <uf_layer.h>

#include <uf_sf_ugs_mesh.h>

// NX9 wizard

#include <ug_session.hxx>

#include <ug_exception.hxx>

#include <uf_exit.h>

#include <ug_info_window.hxx>

// NXOpen C++ API

#include <NXOpen/Annotations.hxx>

#include <NXOpen/Annotations_Note.hxx>

#include <NXOpen/Annotations_PmiManager.hxx>

#include <NXOpen/Arc.hxx>

#include <NXOpen/Assemblies_Component.hxx>

#include <NXOpen/Assemblies_ComponentAssembly.hxx>

#include <NXOpen/AttributeIterator.hxx>

#include <NXOpen/Axis.hxx>

#include <NXOpen/AxisCollection.hxx>

#include <NXOpen/BasePart.hxx>

#include <NXOpen/Body.hxx>

#include <NXOpen/BodyCollection.hxx>

#include <NXOpen/BodyDumbRule.hxx>

#include <NXOpen/Builder.hxx>

#include <NXOpen/CurveDumbRule.hxx>

#include <NXOpen/CurveDumbRule.hxx>

#include <NXOpen/Features_PointFeatureBuilder.hxx>

#include <NXOpen/GeometricAnalysis_AnalysisManager.hxx>

#include <NXOpen/GeometricAnalysis_SimpleInterference.hxx> 

#include <NXOpen/Features_CompositeCurveBuilder.hxx>

#include <NXOpen/CartesianCoordinateSystem.hxx>

#include <NXOpen/ColorManager.hxx>

#include <NXOpen/CoordinateSystemCollection.hxx>

#include <NXOpen/Curve.hxx>

#include <NXOpen/CurveCollection.hxx>

#include <NXOpen/CylindricalCoordinateSystem.hxx>

#include <NXOpen/DatumAxis.hxx>

#include <NXOpen/DatumPlane.hxx>

#include <NXOpen/Direction.hxx>

#include <NXOpen/DirectionCollection.hxx>

#include <NXOpen/DisplayableObject.hxx>

#include <NXOpen/DisplayManager.hxx>

#include <NXOpen/Display_Background.hxx>

#include <NXOpen/Display_DynamicSection.hxx> 

#include <NXOpen/Display_DynamicSectionBuilder.hxx>

#include <NXOpen/Display_DynamicSectionCollection.hxx>

#include <NXOpen/Edge.hxx>

#include <NXOpen/EdgeDumbRule.hxx>

#include <NXOpen/Ellipse.hxx>

#include <NXOpen/Expression.hxx>

#include <NXOpen/ExpressionCollection.hxx>

#include <NXOpen/Face.hxx>

#include <NXOpen/FaceBodyRule.hxx>

#include <NXOpen/FaceConnectedBlendRule.hxx>

#include <NXOpen/FaceDumbRule.hxx>

#include <NXOpen/Features_MirrorBodyBuilder.hxx>

#include <NXOpen/Features_WaveDatumBuilder.hxx>

#include <NXOpen/Features_WavePointBuilder.hxx>

#include <NXOpen/Features_WaveSketchBuilder.hxx>

#include <NXOpen/Features_AdmMoveFaceBuilder.hxx> 

#include <NXOpen/Features_AdmResizeFaceBuilder.hxx>

#include <NXOpen/Features_BaseFeatureCollection.hxx>

#include <NXOpen/Features_BodyFeature.hxx>

#include <NXOpen/Features_BooleanBuilder.hxx> 

#include <NXOpen/Features_BoundedPlane.hxx>

#include <NXOpen/Features_BoundedPlaneBuilder.hxx>

#include <NXOpen/Features_BridgeCurveBuilderEx.hxx>

#include <NXOpen/Features_DatumAxisBuilder.hxx>

#include <NXOpen/Features_DatumCsys.hxx>

#include <NXOpen/Features_DatumPlaneBuilder.hxx>

#include <NXOpen/Features_DatumPlaneBuilder.hxx>

#include <NXOpen/Features_DatumPlaneFeature.hxx>

#include <NXOpen/Features_DeleteFace.hxx>

#include <NXOpen/Features_DeleteFaceBuilder.hxx>

#include <NXOpen/Features_DivideCurveBuilder.hxx>

#include <NXOpen/Features_DividefaceBuilder.hxx>

#include <NXOpen/Features_EdgeBlend.hxx>

#include <NXOpen/Features_Extrude.hxx>

#include <NXOpen/Features_ExtrudeBuilder.hxx>

#include <NXOpen/Features_ExtractFaceBuilder.hxx>

#include <NXOpen/Features_Feature.hxx>

#include <NXOpen/Features_FeatureGroup.hxx>

#include <NXOpen/Features_FeatureCollection.hxx>

#include <NXOpen/Features_FitCurve.hxx>

#include <NXOpen/Features_FitCurveBuilder.hxx>

#include <NXOpen/Features_GeometricConstraintData.hxx>

#include <NXOpen/Features_GeometricConstraintDataManager.hxx>

#include <NXOpen/Features_MoveObjectBuilder.hxx>

#include <NXOpen/Features_OptimizeFaceBuilder.hxx>

#include <NXOpen/Features_ProjectCurve.hxx>

#include <NXOpen/Features_ProjectCurveBuilder.hxx>

#include <NXOpen/Features_ResizeBlendBuilder.hxx>

#include <NXOpen/Features_Revolve.hxx>

#include <NXOpen/Features_RevolveBuilder.hxx>

#include <NXOpen/Features_SewBuilder.hxx>

#include <NXOpen/Features_SplitBody.hxx>

#include <NXOpen/Features_SplitBodyBuilder.hxx>

#include <NXOpen/Features_StudioSpline.hxx>

#include <NXOpen/Features_StudioSplineBuilder.hxx>

#include <NXOpen/Features_StudioSplineBuilderEx.hxx>

#include <NXOpen/Features_ThickenBuilder.hxx>

#include <NXOpen/Features_TrimSheet.hxx>

#include <NXOpen/Features_TrimSheetBuilder.hxx>

#include <NXOpen/Features_TrimBody2Builder.hxx>

#include <NXOpen/Features_Brep.hxx>

#include <NXOpen/FileNew.hxx>

#include <NXOpen/GeometricUtilities_CurveFitData.hxx>

#include <NXOpen/GeometricUtilities_EntityUsageInfo.hxx>

#include <NXOpen/GeometricUtilities_EntityUsageInfoList.hxx>

#include <NXOpen/GeometricUtilities_ParentEquivalencyMap.hxx>

#include <NXOpen/GeometricUtilities_ParentEquivalencyMapList.hxx>

#include <NXOpen/GeometricUtilities_ReplAsstBuilder.hxx>

#include <NXOpen/GeometricUtilities_BooleanOperation.hxx>
#include <NXOpen/GeometricUtilities_BooleanOperation.hxx>

#include <NXOpen/GeometricUtilities_BooleanToolBuilder.hxx>

#include <NXOpen/GeometricUtilities_BoundingObjectBuilder.hxx>

#include <NXOpen/GeometricUtilities_BoundingObjectBuilderList.hxx>

#include <NXOpen/GeometricUtilities_BridgeCurveConnectivity.hxx>

#include <NXOpen/GeometricUtilities_Continuity.hxx>

#include <NXOpen/GeometricUtilities_DepthSkewBuilder.hxx>

#include <NXOpen/GeometricUtilities_Extend.hxx>

#include <NXOpen/GeometricUtilities_FacePlaneToolBuilder.hxx>

#include <NXOpen/GeometricUtilities_FaceSetData.hxx> 
#include<NXOpen/GeometricUtilities_FeatureOffset.hxx>

 #include <NXOpen/GeometricUtilities_FeatureOptions.hxx>

#include <NXOpen/GeometricUtilities_Limits.hxx>

#include <NXOpen/GeometricUtilities_OnPathDimensionBuilder.hxx>

#include <NXOpen/GeometricUtilities_ProjectionOptions.hxx>

#include <NXOpen/IBaseCurve.hxx>

#include <NXOpen/IBody.hxx>

#include <NXOpen/Information.hxx>

#include <NXOpen/IParameterizedSurface.hxx>

#include <NXOpen/Line.hxx>

#include <NXOpen/LineCollection.hxx>

#include <NXOpen/ListingWindow.hxx>

#include <NXOpen/Layer.hxx>

#include <NXOpen/Layer_LayerManager.hxx>

#include <NXOpen/MeasureAngle.hxx>

#include <NXOpen/MeasureBodies.hxx>

#include <NXOpen/MeasureBodyBuilder.hxx>

#include <NXOpen/MeasureDistance.hxx>

#include <NXOpen/MeasureDistanceBuilder.hxx>

#include <NXOpen/MeasureFaces.hxx> 

#include <NXOpen/MeasureManager.hxx>

#include <NXOpen/Menubar_MenubarManager.hxx>

#include <NXOpen/ModelingView.hxx>

#include <NXOpen/ModelingViewCollection.hxx> 

#include <NXOpen/NXMessageBox.hxx>

#include <NXOpen/NXObject.hxx> 

#include <NXOpen/NXObjectList.hxx>

#include <NXOpen/NXObjectManager.hxx>

#include <NXOpen/NXString.hxx>

#include <NXOpen/NXException.hxx>

#include <NXOpen/Options_ChangeList.hxx>

#include <NXOpen/Options_OptionsManager.hxx>

#include <NXOpen/Part.hxx>

#include <NXOpen/Part.hxx>

#include <NXOpen/PartCollection.hxx>

#include <NXOpen/Plane.hxx>

#include <NXOpen/PlaneCollection.hxx>

#include <NXOpen/Point.hxx>

#include <NXOpen/PointCollection.hxx>

#include <NXOpen/Preferences_PartPreferences.hxx>

#include <NXOpen/Preferences_PartVisualizationEmphasis.hxx>

#include <NXOpen/Preferences_PartVisualizationColorSetting.hxx>

#include <NXOpen/Preferences_SessionAssemblies.hxx>

#include <NXOpen/Preferences_SessionModeling.hxx> #include <NXOpen/Preferences_SessionPreferences.hxx>

#include <NXOpen/Preferences_SessionUserInterfaceUI.hxx>

#include <NXOpen/Preferences_SessionVisualizationEmphasis.hxx>

#include <NXOpen/Preferences_SessionVisualizationScreen.hxx>

#include <NXOpen/RegionPoint.hxx>

#include <NXOpen/RegionPointList.hxx>

#include <NXOpen/Scalar.hxx>

#include <NXOpen/ScalarCollection.hxx>

#include <NXOpen/ScCollector.hxx>

#include <NXOpen/ScCollectorCollection.hxx>

#include <NXOpen/ScRuleFactory.hxx>

#include <NXOpen/Section.hxx>

#include <NXOpen/SectionCollection.hxx>

#include <NXOpen/SelectDatumPlane.hxx>

#include <NXOpen/SelectFace.hxx>

#include <NXOpen/SelectFaceList.hxx>

#include <NXOpen/SelectPointList.hxx>

#include <NXOpen/SelectBodyList.hxx>

#include <NXOpen/SelectCurve.hxx>

#include <NXOpen/SelectDisplayableObject.hxx>

#include <NXOpen/SelectDisplayableObjectList.hxx>

#include <NXOpen/Selection.hxx>

#include <NXOpen/SelectionIntentRule.hxx>

#include <NXOpen/SelectIParameterizedSurface.hxx>

#include <NXOpen/SelectNXObjectList.hxx>

#include <NXOpen/SelectObject.hxx>

#include <NXOpen/SelectObjectList.hxx>

#include <NXOpen/SelectTaggedObjectList.hxx>

#include <NXOpen/Session.hxx>

#include <NXOpen/Sketch.hxx>

#include <NXOpen/SketchCollection.hxx>

#include <NXOpen/SmartObject.hxx>
#include <NXOpen/SelectDisplayableObject.hxx>

#include <NXOpen/SelectDisplayableObjectList.hxx>

#include <NXOpen/Selection.hxx>

#include <NXOpen/SelectionIntentRule.hxx>

#include <NXOpen/SelectIParameterizedSurface.hxx>

#include <NXOpen/SelectNXObjectList.hxx>

#include <NXOpen/SelectObject.hxx>

#include <NXOpen/SelectObjectList.hxx>

#include <NXOpen/SelectTaggedObjectList.hxx>

#include <NXOpen/Session.hxx>

#include <NXOpen/Sketch.hxx>

#include <NXOpen/SketchCollection.hxx>

#include <NXOpen/SmartObject.hxx>

#include <NXOpen/Spline.hxx>

#include <NXOpen/SplineCollection.hxx>

#include <NXOpen/TaggedObject.hxx>

//#include <NXOpen/UI.hxx>

#include <NXOpen/Unit.hxx>

#include <NXOpen/UnitCollection.hxx>

#include <NXOpen/Update.hxx>

#include <NXOpen/View.hxx>

#include <NXOpen/ViewCollection.hxx>

#include <NXOpen/WCS.hxx>

#include <NXOpen/Xform.hxx>

#include <NXOpen/XformCollection.hxx>

using namespace NXOpen; 
using namespace NXOpen::Assemblies; 
using namespace NXOpen::Preferences; 
using namespace NXOpen::Features;
void GetBodiesAndFaces();

#endif