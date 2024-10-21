#include "Header.hpp"

using namespace std;
Session* theSession=nullptr;
Part* workPart = nullptr;
Part* displayPart = nullptr;
ListingWindow* listingWindow = nullptr;
LogFile* logFile = nullptr;

void GetBodiesAndFaces() {
	try
	{
		theSession = Session::GetSession();
		workPart = theSession->Parts()->Work();
		displayPart = theSession->Parts()->Display();
		listingWindow = theSession->ListingWindow();
		logFile = theSession->LogFile();
		listingWindow->Open();

		vector<Body*> lsBodies;

		//if (workPart!=NULL)
		//{
		//	//NXOpen::BodyCollection* bodyCollection = workPart->Bodies();
		//	
		//	tag_t bodyTag = null_tag;
		//	UF_OBJ_cycle_objs_in_part(displayPart->Tag(), UF_solid_type, &bodyTag);
		//	while (bodyTag!=NULL)
		//	{
		//		int bodyType;
		//		UF_MODL_ask_body_type(bodyTag, &bodyType);
		//		if (bodyType==UF_MODL_SOLID_BODY)
		//		{
		//			Body* body(dynamic_cast<Body*>(NXObjectManager::Get(bodyTag)));
		//			if (body!=NULL)
		//			{
		//				lsBodies.push_back(body);
		//			}
		//		}
		//		UF_OBJ_cycle_objs_in_part(displayPart->Tag(), UF_solid_type, &bodyTag);
		//	}
		int nOfBodies=0;
			BodyCollection* bodyList = workPart->Bodies();
			BodyCollection::iterator itr;
			for (itr = bodyList->begin(); itr != bodyList->end(); ++itr)
			{
				lsBodies.push_back(*itr);
				listingWindow->WriteLine("Body: "+ nOfBodies++);

			}
			//// Get the tag of the work part
			//tag_t workPartTag = workPart->Tag();

			//// Get all bodies in the work part
			//int numBodies = 0;
			//tag_t* bodyTags = nullptr;

			//// Free the allocated memory for body tags
			//UF_free(bodyTags);
			listingWindow->WriteLine("No of bodies in the part : ");
			listingWindow->WriteLine("Please check the syslog for additional details. (Help → Log File → Show Log File)");
		
		listingWindow->Close();
	}
	catch (const NXException&ex)
	{

	}
}
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