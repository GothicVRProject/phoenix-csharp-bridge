#define DllExport extern "C" __declspec( dllexport )

#include <iostream>
#include <strings.h>
#include <phoenix/vdfs.hh>

using namespace phoenix;

DllExport vdf_header* getVDFHeader(char* vdfPath) {
	auto vdf = vdf_file::open(vdfPath);

	auto header = new vdf_header;
	header->comment = vdf.header.comment;
	header->entry_count = vdf.header.entry_count;
	header->file_count = vdf.header.file_count;
	header->signature = vdf.header.signature;
	header->size = vdf.header.size;
	header->timestamp = vdf.header.timestamp;
	header->version = vdf.header.version;

	return header;
}


DllExport const char* getHeaderComment(vdf_header* header) {
	if (header->comment.empty())
		return NULL;

	return header->comment.c_str();
}

DllExport void disposeHeader(vdf_header* header) {
	if(header != NULL) {
        delete header;
        header = NULL;
    }
}



int main(int argc, char** argv) {
//	std::cout << ":Test: " << outComment << std::endl;

	auto header = getVDFHeader((char*)"C:\\Program Files (x86)\\Steam\\steamapps\\common\\Gothic\\Data\\SystemPack.vdf");


	std::cout << "headerComment: " << header->comment << header->comment.empty() << "END;" << std::endl;



	int a;
	std::cin >> a;

	return 0;
}
