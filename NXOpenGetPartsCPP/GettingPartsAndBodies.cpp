﻿//Including NXOpenHeaders.hpp it also contains standard functions call
#include "NXOpenHeaders.hpp"

//Initialising session, work and display parts, listing window and log file from the session
Session* theSession=nullptr;
Part* workPart = nullptr;
Part* displayPart = nullptr;
ListingWindow* listingWindow = nullptr;
LogFile* logFile = nullptr;
UI* theUI = NULL;

//storing all the bodies, faces and edges in vector lists
vector<Body*> lsBodies=vector<Body*>();
vector<Face*> lsFaces=vector<Face*>();
vector<Edge*> lsEdges=vector<Edge*>();

//Getting session, work and display parts, listing window from the session using User Functions (UF) APIs
bool GetSessionAndPartsUF() {

	try
	{
		tag_t workPartTagUF = UF_ASSEM_ask_work_part();
		//tag_t workPartTag = Session::GetSession()->Parts()->Work()->Tag();
		tag_t displayPartUF = UF_PART_ask_display_part();

		UF_UI_open_listing_window();
		UF_UI_write_listing_window("Got work and display parts via UF: ");

		workPart = dynamic_cast<Part*>(NXObjectManager::Get(workPartTagUF));
		displayPart = dynamic_cast<Part*>(NXObjectManager::Get(displayPartUF));
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

//Getting session, work and display parts, listing window from the session using NXOpen
bool GetSessionAndParts() {

	try
	{
		theSession = Session::GetSession();
		workPart = theSession->Parts()->Work();
		displayPart = theSession->Parts()->Display();
		listingWindow = theSession->ListingWindow();
		logFile = theSession->LogFile();
		listingWindow->Open();
		//theUI= UI::GetUI();
		
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

//Getting Bodies from the work part and storing them in list which is initialised at begining
void GetBodies() {
	try
	{
		//calling method to get session, work and display parts, listing window from the session
		GetSessionAndParts();


		if (theSession != NULL && workPart != NULL && displayPart != NULL)
		{
			BodyCollection* bodyList = workPart->Bodies();

			//Iterating via each body in the body collection and adding each body to a list
			BodyCollection::iterator itr;
			for (itr = bodyList->begin(); itr != bodyList->end(); ++itr)
			{
				lsBodies.push_back(*itr);
			}

			//Writing Number of bodies to Listing Window and closing the listing window, string.c_str() is mandatory to show exact string
			string str1 = "No of bodies in the part : " + to_string(lsFaces.size());
			listingWindow->WriteLine(str1.c_str());
			listingWindow->Close();
		}
	}

	catch (const NXOpen::NXException& e) {
		listingWindow->WriteLine(("NX Exception: " + string(e.Message())).c_str());
	}
	catch (const std::exception& e) {
		listingWindow->WriteLine("Standard Exception: " + std::string(e.what()));
	}
	catch (...) {
		listingWindow->WriteLine("Unknown exception caught.");
	}
}

void GetFaces() { //getting errors have to fix**********************************************************************
	//std::vector <Face*> faceArray = bdy->GetFaces();

	for (int i = 0; i < (int)lsBodies.size(); i++)
	{
		std::vector <Face*> faceArray;
		uf_list_p_t faces=NULL;
		try
		{
			if (lsBodies[i] != NULL)
			{
				UF_MODL_ask_body_faces(lsBodies[i]->Tag(), &faces);

				uf_list_p_t currentFaces = faces;
				while (currentFaces!=NULL)
				{
					Face* face = dynamic_cast<Face*>(NXObjectManager::Get(currentFaces->eid));
					lsFaces.push_back(face);
					currentFaces->next;
				}
				/*faceArray = lsBodies[i]->GetFaces();
				if (faceArray.size() >= 0)
				{
					for (int j = 0; j < (int)faceArray.size(); j++)
					{
						
						lsFaces.push_back(faceArray[j]);
					}
				}*/
			}
		}
		catch (const NXException& e)
		{
			listingWindow->WriteLine(("NX Exception: " + string(e.Message())).c_str());
		}
	}
	listingWindow->Open();
	listingWindow->WriteLine(to_string(lsFaces.size()).c_str());
}
//static std::pair<double, double> GetMinMaxDistance(
//	NXOpen::DisplayableObject* obj1,
//	NXOpen::DisplayableObject* obj2,
//	
//NXOpen::Direction direction)
//{
//	try
//	{
//		// Get the Session and Work Part
//		NXOpen::Session* theSession = NXOpen::Session::GetSession();
//		NXOpen::Part* workPart = theSession->Parts()->Work();
//		NXOpen::MeasureManager* measureManager = workPart->MeasureManager();
//
//		// Create a Direction object
//		NXOpen::Direction* measureDirection = workPart->Directions()->CreateDirection(direction,SmartObject::UpdateOption::UpdateOptionWithinModeling);
//
//		// Get the unit for measurement (default unit of the part)
//		NXOpen::Unit* distanceUnit = workPart->UnitCollection()->FindObject("MilliMeter"); // Replace with "Meter" or other units if required
//
//		// Measure minimum distance
//		NXOpen::MeasureDistance* minMeasure = measureManager->NewDistance(
//			distanceUnit,               // Unit
//			obj1,                       // First object
//			obj2,                       // Second object
//			measureDirection,           // Direction
//			NXOpen::MeasureManager::ProjectionTypeMinimum); // Minimum distance projection
//		double minDistance = minMeasure->Value();
//		delete minMeasure;
//
//		// Measure maximum distance
//		NXOpen::MeasureDistance* maxMeasure = measureManager->NewDistance(
//			distanceUnit,               // Unit
//			obj1,                       // First object
//			obj2,                       // Second object
//			measureDirection,           // Direction
//			NXOpen::MeasureManager::ProjectionTypeMaximum); // Maximum distance projection
//		double maxDistance = maxMeasure->Value();
//		delete maxMeasure;
//
//		// Clean up
//		delete measureDirection;
//
//		return { minDistance, maxDistance };
//	}
//	catch (const NXOpen::NXException& ex)
//	{
//		std::cerr << "NX Exception: " << ex.Message() << std::endl;
//		return { 0.0, 0.0 };
//	}
//	catch (...)
//	{
//		std::cerr << "An unexpected error occurred." << std::endl;
//		return { 0.0, 0.0 };
//	}
//}
//libufun_cae.lib;libnxopencpp_annotations.lib;libnxopencpp_assemblies.lib;libnxopencpp_bodydes.lib;
// libnxopencpp_cae.lib;libnxopencpp_cam.lib;libnxopencpp_die.lib;libnxopencpp_display.lib;libnxopencpp_drafting.lib;
// libnxopencpp_drawings.lib;libnxopencpp_facet.lib;libnxopencpp_features.lib;libnxopencpp_fields.lib;
// libnxopencpp_formboard.lib;libnxopencpp_gateway.lib;libnxopencpp_geometricanalysis.lib;libnxopencpp_geometricutilities.lib;
// libnxopencpp_issue.lib;libnxopencpp_layer.lib;libnxopencpp_layout2d.lib;libnxopencpp_mechatronics.lib;libnxopencpp_motion.lib;
// libnxopencpp_optimization.lib;libnxopencpp_options.lib;libnxopencpp_partfamily.lib;libnxopencpp_pdm.lib;
// libnxopencpp_physmat.lib;libnxopencpp_positioning.lib;libnxopencpp_preferences.lib;libnxopencpp_routing.lib;
// libnxopencpp_shapesearch.lib;libnxopencpp_sheetmetal.lib;libnxopencpp_sim.lib;libnxopencpp_tooling.lib;
// libnxopencpp_userdefinedobjects.lib;libnxopencpp_validate.lib;libnxopencpp_visualreporting.lib;libnxopencpp_weld.lib;
// libugopenint_cae.lib;libnxopenuicpp.lib;libopenpp.lib;
// libopenintpp.lib;libvmathpp.lib;Netapi32.lib;msvcrt.lib

void DeleteFeatures(NXOpen::Part* part, std::string featureName) {
	if (part==NULL)
	{
		return;
	}
	
		Features::FeatureCollection* featureCollection = part->Features();

		std::vector<tag_t> featuresToDelete;

		for (Features::Feature* feature : featureCollection->GetFeatures())
		{
			if (feature->Name().GetText() == featureName)
			{
				featuresToDelete.push_back(feature->Tag());
			}
		}

		if (featuresToDelete.empty())
		{
			return;
		}

		UF_initialize();

		uf_list_p_t featureList = NULL;
		
		for (tag_t tag:featuresToDelete)
		{
			//UF_MODL_create_list(&featureList);
			UF_MODL_put_list_item(featureList, tag);
		}

		if (featureList!=NULL)
		{
			UF_MODL_delete_feature(featureList);
			UF_MODL_delete_list(&featureList);
		}

		part->Save(BasePart::SaveComponentsTrue,BasePart::CloseAfterSaveFalse);

		UF_terminate();
}