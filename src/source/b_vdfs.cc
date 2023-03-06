#define DllExport extern "C" __declspec( dllexport )

#include <phoenix/vdfs.hh>

using namespace phoenix;


DllExport vdf_file* createVDFContainer() {
	return new vdf_file("Root");
}

DllExport void addVDFToContainer(vdf_file* vdfContainer, char* newVdfPath) {
	vdfContainer->merge(vdf_file::open(newVdfPath));
}

DllExport const vdf_entry* getVDFEntry(vdf_file* vdfContainer, char* fileName) {
    return static_cast<const vdf_file*>(vdfContainer)->find_entry(fileName);
}
