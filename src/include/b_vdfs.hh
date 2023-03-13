#pragma once

#include <phoenix/vdfs.hh>
#include <exports.hh>

using namespace phoenix;


EXPORT vdf_file* createVDFContainer();
EXPORT void addVDFToContainer(vdf_file* vdfContainer, char* newVdfPath);
EXPORT const vdf_entry* getVDFEntry(vdf_file* vdfContainer, char* fileName);
EXPORT void disposeVDFContainer(vdf_file* vdfContainer);
