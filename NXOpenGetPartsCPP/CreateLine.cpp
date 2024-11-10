#include "NXOpenHeaders.hpp"

//Session, work and display parts, listing window are already declared in NXOpenHeaders.hpp as extern,
//so we can use them here without declaring again

Line* line;
void CreateLine() {
	try {

			GetSessionAndParts();
		
			if (workPart != NULL || displayPart != NULL)
			{
				//Creating line with two 3D spaces 
				Point3d startPoind3D(10, 10, 10);
				Point3d endPoind3D(10, 10, 110);
				line = workPart->Curves()->CreateLine(startPoind3D, endPoind3D);


				//if (status == 0)
				//{
				//	double startPoint[3] = { lineCoords1.start_point[0],lineCoords1.start_point[1],lineCoords1.start_point[2] };
				//	double endPoint[3] = { lineCoords1.end_point[0],lineCoords1.end_point[1],lineCoords1.end_point[2] };

				//	double midPointCoords[3];
				//	for (int i = 0; i < 3; i++)
				//	{
				//		midPointCoords[i] = (lineCoords1.start_point[i] + lineCoords1.end_point[i]) / 2;
				//	}
				//	string output = "Point: " + to_string(midPointCoords[0]) + "," + to_string(midPointCoords[1]) + "," + to_string(midPointCoords[2]);
				//	UF_UI_open_listing_window();
				//	//UF_UI_write_listing_window(output.c_str());
				//	listingWindow->WriteLine(output.c_str());
				//	double P2Coor[3]{ 110,10,10 };
				//	tag_t midpt;
				//	tag_t p2;
				//	tag_t l4;
				//	UF_CURVE_create_point(midPointCoords, &midpt);
				//	UF_CURVE_create_point(P2Coor, &p2);
				//	UF_CURVE_line_t lineParms;
				//	UF_CURVE_ask_point_data(midpt, lineParms.start_point);
				//	UF_CURVE_ask_point_data(p2, lineParms.end_point);
				//	UF_CURVE_create_line(&lineParms, &l4);
				//	UF_DISP_set_display(UF_DISP_ALL_ACTIVE_VIEWS);

				//	/*double parameter = 0.5;
				//	double* point;
				//	int numPoints;
				//	status = UF_MODL_ask_curve_points(l1->Tag(), 0,0,0,&numPoints,&point);
				//	listingWindow->Open();
				//	listingWindow->WriteLine(to_string(numPoints));*/
				//}

				//////creating line with two points
				////Point* startPointP1 = workPart->Points()->CreatePoint(startPoind3D);
				////Point* endPointP2 = workPart->Points()->CreatePoint(endPoind3D);
				////Line* l2 = workPart->Curves()->CreateLine(startPointP1, endPointP2);
				////l2->SetVisibility(SmartObject::VisibilityOptionVisible);

				//////creating line with two points created by User Function API
				////UF_CURVE_line_p_t lineCoords=NULL;
				////lineCoords->start_point[0] = 10;
				////lineCoords->start_point[1] = 10;
				////lineCoords->start_point[2] = 10;
				////lineCoords->end_point[0] = 10;
				////lineCoords->end_point[1] = 110;
				////lineCoords->end_point[2] = 10;
				////tag_t l3;
				////UF_CURVE_create_line(lineCoords, &l3);

				////creating line with two points by UF API, double as input
				///*double P1Coor[3] = { 10,10,10 };
				//double P2Coor[3]{ 110,10,10 };
				//tag_t p1;
				//tag_t p2;
				//UF_CURVE_create_point(P1Coor, &p1);
				//UF_CURVE_create_point(P2Coor, &p2);
				//UF_CURVE_line_p_t lineParms;
				//UF_CURVE_ask_point_data(p1, lineParms->start_point);
				//UF_CURVE_ask_point_data(p1, lineParms->end_point);
				//UF_CURVE_create_line(lineParms, &l3);
				//UF_DISP_set_display(UF_DISP_ALL_ACTIVE_VIEWS);*/

				//listingWindow->WriteLine("3 lines created succesfully");
			}
	}
	catch (const std::exception e) {
		//listingWindow->WriteLine(NXString(e));
	}
}

void GetLineDetails() {
	//Getting line details
	UF_CURVE_line_t lineCoords1;
	int status = UF_CURVE_ask_line_data(line->Tag(), &lineCoords1);
}

void CreatingNewPointFromMidPointOfline() {

	GetSessionAndParts();
	/*Point3d lineStartPoint = line->StartPoint();
	Point3d lineEndPoint = line->EndPoint();*/

	//Getting start end and mid points of the original line
	double lineStartPoint[] = {line->StartPoint().X, line->StartPoint().Y, line->StartPoint().Z};
	double lineEndPoint[] = {line->EndPoint().X, line->EndPoint().Y, line->EndPoint().Z};

	double midPt[] = { 
		(lineEndPoint[0] + lineStartPoint[0]) / 2,
		(lineEndPoint[1] + lineStartPoint[1]) / 2, 
		(lineEndPoint[2] + lineStartPoint[2]) / 2 
	};

	Point* midPoint = workPart->Points()->CreatePoint(Point3d(midPt[0], midPt[1], midPt[2]));
	midPoint->SetVisibility(SmartObject::VisibilityOptionVisible);

	//Getting Direction vector for original line
	double directionVectorOfLine[] = {
		lineEndPoint[0]-lineStartPoint[0],
		lineEndPoint[1]-lineStartPoint[1],
		lineEndPoint[2]-lineStartPoint[2]
	};

	//The direction vector we calculated above has a magnitude (or length) based on the distance between the start and end points.
	//However, to work with directions without scaling, we often use a unit vector—a vector with a magnitude of 1 that points in the same direction.
	//to get unit vector, divide each component of vector with length
	double length = sqrt(
		directionVectorOfLine[0]*directionVectorOfLine[0]+
		directionVectorOfLine[1]*directionVectorOfLine[1]+
		directionVectorOfLine[2]*directionVectorOfLine[2]
	);

	double unitVectorOfline[] = {
		directionVectorOfLine[0]/length,
		directionVectorOfLine[1]/length,
		directionVectorOfLine[2]/length,
	};

	// Let us assume that it is in XY plane to reduce complexity, now the perpendicular to(X, Y, 0) will be(-Y, X, 0)
	//If we need it in YZ plane, perpendicular to (0,Y,Z) will be (0,-Z,Y)
	double perpendicularVectorToLine[] = {
		-unitVectorOfline[1],
		unitVectorOfline[0],
		0
	};

	//Creating a point perpendicular to line in some distance in XY plane
	double distance = 100;
	double perpendicularPt[] = {
		midPt[0] + perpendicularVectorToLine[0] * distance,
		midPt[1] + perpendicularVectorToLine[1] * distance,
		midPt[2] + perpendicularVectorToLine[2] * distance
	};
	Point3d perpendicularPt3d(perpendicularPt[0], perpendicularPt[1], perpendicularPt[2]);
	Point* pointPerpendicularToline = workPart->Points()->CreatePoint(perpendicularPt3d);
	pointPerpendicularToline->SetVisibility(SmartObject::VisibilityOptionInvisible);

	listingWindow->WriteLine("point created");
}

void CreatingLinePerpendicularToLine() {
	//Calculating Mid Point from start and end points, by adding and dividing the corresponding components by 2
	Point3d startPointOfline = line->StartPoint();
	Point3d endPointOfline = line->EndPoint();

	Point3d midPoint(
		(startPointOfline.X+endPointOfline.X)/2, 
		(startPointOfline.Y + endPointOfline.Y) / 2, 
		(startPointOfline.Z + endPointOfline.Z) / 2 
	);

	//calculating direction vector of original line, we can use double[] array or vector3D to store the direction vector
	Vector3d directionVectorOfOriginalLine(
		endPointOfline.X-startPointOfline.X,
		endPointOfline.Y-startPointOfline.Y,
		endPointOfline.Z-startPointOfline.Z
	);

	//Calculate magnitude or length of the original line to calculate unit vector
	double length = sqrt(
		directionVectorOfOriginalLine.X*directionVectorOfOriginalLine.X+
		directionVectorOfOriginalLine.Y*directionVectorOfOriginalLine.Y+
		directionVectorOfOriginalLine.Z*directionVectorOfOriginalLine.Z
	);

	//unit vector of original line
	Vector3d unitVectorOfOriginalline(
		directionVectorOfOriginalLine.X / length,
		directionVectorOfOriginalLine.Y / length,
		directionVectorOfOriginalLine.Z / length
	);

	//Perpendicuar direction vector, let us assume it on YZ plane,
	//perpendicular direction vector for (0,Y,Z) is (0,-Z,Y)
	Vector3d unitVectorOfNewLine(
		0,
		-unitVectorOfOriginalline.Z,
		unitVectorOfOriginalline.Y
	);

	//Perpendicular end point for new line
	double lengthOfNewLine = 10;
	Point3d perpendicularEndPointForNewLine(
		midPoint.X+unitVectorOfNewLine.X*lengthOfNewLine,
		midPoint.Y+unitVectorOfNewLine.Y*lengthOfNewLine,
		midPoint.Z+unitVectorOfNewLine.Z*lengthOfNewLine
	);

	Line* newLine = workPart->Curves()->CreateLine(midPoint, perpendicularEndPointForNewLine);
	listingWindow->WriteLine("perpendicular line created");
}