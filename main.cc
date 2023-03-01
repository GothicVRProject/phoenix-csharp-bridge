#define DllExport extern "C" __declspec( dllexport )

#include <iostream>
#include <strings.h>
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

// DllExport const char* getHeaderComment(vdf_header* header) {
// 	if (header->comment.empty())
// 		return NULL;

// 	return header->comment.c_str();
// }

DllExport void disposeVDFContainer(vdf_file* vdfContainer) {
	if(vdfContainer != NULL) {
        delete vdfContainer;
        vdfContainer = NULL;
    }
}



int main(int argc, char** argv) {
	// getVDFHeader((char*)"C:\\Program Files (x86)\\Steam\\steamapps\\common\\Gothic\\Data\\SystemPack.vdf");

	// std::cout << "headerComment: " << header->comment << header->comment.empty() << "END;" << std::endl;


	int a;
	std::cin >> a;
	return 0;
}
