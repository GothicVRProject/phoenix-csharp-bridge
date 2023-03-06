#pragma once
#define DllExport extern "C" __declspec( dllexport )

#include <phoenix/vdfs.hh>

using namespace phoenix;


DllExport vdf_file* createVDFContainer();
DllExport void addVDFToContainer(vdf_file* vdfContainer, char* newVdfPath);
DllExport const vdf_entry* getVDFEntry(vdf_file* vdfContainer, char* fileName);
DllExport void disposeVDFContainer(vdf_file* vdfContainer);
