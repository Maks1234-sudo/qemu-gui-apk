#include <archive.h>
#include <archive_entry.h>

bool untar_xz(const char* archive_path, const char* dest_path) {
    struct archive *a = archive_read_new();
    struct archive *ext = archive_write_disk_new();
    archive_read_support_format_tar(a);
    archive_read_support_filter_xz(a);

    if (archive_read_open_filename(a, archive_path, 10240) != ARCHIVE_OK)
        return false;

    struct archive_entry *entry;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        archive_write_header(ext, entry);
        const void *buff;
        size_t size;
        la_int64_t offset;
        while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
            archive_write_data(ext, buff, size);
        }
        archive_write_finish_entry(ext);
    }
    archive_read_close(a);
    archive_read_free(a);
    archive_write_close(ext);
    archive_write_free(ext);
    return true;
}