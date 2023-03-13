#include <phoenix/vdfs.hh>
#include <exports.hh>

using namespace phoenix;


EXPORT vdf_file* createVDFContainer() {
	return new vdf_file("Root");
}

EXPORT void addVDFToContainer(vdf_file* vdfContainer, char* newVdfPath) {
	vdfContainer->merge(vdf_file::open(newVdfPath));
}

EXPORT const vdf_entry* getVDFEntry(vdf_file* vdfContainer, char* fileName) {
    return static_cast<const vdf_file*>(vdfContainer)->find_entry(fileName);
}

EXPORT void disposeVDFContainer(vdf_file* vdfContainer) {
  delete vdfContainer;
}
