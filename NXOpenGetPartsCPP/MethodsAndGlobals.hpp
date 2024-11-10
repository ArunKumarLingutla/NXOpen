#pragma once
#ifndef METHODSANDFUNCTIONS_HPP
#define METHODSANDFUNCTIONS_HPP

//I am not passing any NX objects as parameters into these methods so that I can declare them here
//If I have to pass any NX object I have to declare them in NXOpenHeaders.hpp or call the API required such as NXOpen/Body.hxx and declare it here
void GetBodies();
bool GetSessionAndParts();
void GetFaces();
void CreateLine();
void GetLineDetails();
void CreatingNewPointFromMidPointOfline();
void CreatingLinePerpendicularToLine();
#endif // !METHODSANDFUNCTIONS_HPP
