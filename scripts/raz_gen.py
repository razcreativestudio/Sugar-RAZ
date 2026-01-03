import sys
import os
from datetime import datetime

TEMPLATE_H = """/* * DESKRIPSI UPDATE: {date}
 * Versi: 1.0.0
 * Pembaruan: Inisialisasi awal file header.
 */

#ifndef {guard}
#define {guard}

// Kelas {classname}
// Penjelasan: [TAMBAHKAN DESKRIPSI KELAS DI SINI]
class {classname} {{
public:
    {classname}();
    ~{classname}();

private:
    // Tambahkan variabel member di sini
}};

#endif // {guard}
"""

TEMPLATE_CPP = """/* * DESKRIPSI UPDATE: {date}
 * Versi: 1.0.0
 * Pembaruan: Implementasi awal logika.
 */

#include "{classname}.h"
#include <iostream>

// Constructor
{classname}::{classname}() {{
    // Inisialisasi logika di sini
}}

// Destructor
{classname}::~{classname}() {{
    // Bersihkan memori di sini
}}
"""

def create_files(base_name):
    if not base_name.startswith("RAZ"):
        print("Peringatan: Nama file sebaiknya diawali dengan 'RAZ'. Menambahkan prefix otomatis...")
        classname = "RAZ" + base_name
    else:
        classname = base_name

    date_str = datetime.now().strftime("%d-%m-%Y")
    guard = classname.upper() + "_H"

    # Paths
    path_h = os.path.join("include", f"{classname}.h")
    path_cpp = os.path.join("src", f"{classname}.cpp")

    # Create Header
    if not os.path.exists(path_h):
        with open(path_h, "w") as f:
            f.write(TEMPLATE_H.format(date=date_str, guard=guard, classname=classname))
        print(f"Berhasil membuat: {path_h}")
    else:
        print(f"Gagal: {path_h} sudah ada.")

    # Create Source
    if not os.path.exists(path_cpp):
        with open(path_cpp, "w") as f:
            f.write(TEMPLATE_CPP.format(date=date_str, classname=classname))
        print(f"Berhasil membuat: {path_cpp}")
    else:
        print(f"Gagal: {path_cpp} sudah ada.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Penggunaan: python3 raz_gen.py <NamaKelas>")
        print("Contoh: python3 raz_gen.py MainController")
        sys.exit(1)

    create_files(sys.argv[1])
