#include <iostream>

#include <libheif/heif.h>
#include <libheif/heif_items.h>

using namespace std;

uint8_t *data;
size_t data_size;

int main() {
  printf("C++14 HEIF RDF Extractor\n");

  // Read GIMI File
  const char *filename = "dataset9_capture1_rdf.heif";
  struct heif_context *ctx = heif_context_alloc();
  heif_error error = heif_context_read_from_file(ctx, filename, NULL);
  if (error.code != heif_error_Ok) {
    cout << "Error reading HEIF file: " << error.message << endl;
    return -1;
  }

  // Get the number of items
  int item_count = heif_context_get_number_of_items(ctx);
  heif_item_id ids[item_count];

  // Get all item IDs
  heif_context_get_list_of_item_IDs(ctx, ids, item_count);

  // Iterate through each item
  for (int i = 0; i < item_count; i++) {
    heif_item_id id = ids[i];
    uint32_t item_type = heif_item_get_item_type(ctx, id);
    const char *mime_type_c = heif_item_get_mime_item_content_type(ctx, id);
    string mime_type(mime_type_c ? mime_type_c : "");

    if (item_type == heif_item_type_mime &&
        mime_type == "text/turtle") {

      heif_item_get_item_data(ctx, id, nullptr, &data, &data_size);
      const char *rdf = reinterpret_cast<const char *>(data);
      cout << "RDF Data: " << rdf << endl;
    }
  }

  return 0;
}