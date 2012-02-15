#ifndef __C_CREATEREPOLIB_LOAD_METADATA_H__
#define __C_CREATEREPOLIB_LOAD_METADATA_H__

#include <glib.h>
#include "constants.h"

struct package_metadata {
    gint64 time_file;
    gint64 size_package;
    char *location_href; // location href (relative path in repo + filename)
    char *location_base; // location base
    char *checksum_type;
    char *primary_xml;
    char *filelists_xml;
    char *other_xml;
//    GStringChunk *chunk;
};

// Key in GHashTable is filename (just filename without path)

GHashTable *new_old_metadata_hashtable();
void *destroy_old_metadata_hashtable();
int load_gz_compressed_xml_metadata(GHashTable *hashtable, const char *primary_xml_path, const char *filelists_xml_path, const char *other_xml_path);
int load_xml_metadata(GHashTable *hashtable, const char *primary_xml_path, const char *filelists_xml_path, const char *other_xml_path);
int locate_and_load_xml_metadata(GHashTable *hashtable, const char *repopath);

#endif /* __C_CREATEREPOLIB_LOAD_METADATA_H__ */
