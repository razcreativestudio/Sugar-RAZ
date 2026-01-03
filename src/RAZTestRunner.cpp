/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Runner khusus untuk testing.
 */

#include "RAZTestEngine.h"

int main() {
    RAZTestEngine tester;
    bool success = tester.runTestSuite();
    return success ? 0 : 1;
}
