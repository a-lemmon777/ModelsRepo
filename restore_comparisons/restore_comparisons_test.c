#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>

#include "cmockery.h"
#include "restore_comparisons.h"

void test_empty_str(void) {
  char* result = restore_comparisons("");
  assert_string_equal("", result);
  free(result);
}

void test_no_comparisons(void) {
  char* result = restore_comparisons("pqrst");
  assert_string_equal("pqrst", result);
  free(result);
}

void test_only_comparisons(void) {
  char* result = restore_comparisons("&lt;&gt;&lt;&gt;");
  assert_string_equal("<><>", result);
  free(result);
}

void test_arithmetic(void) {
  char* result = restore_comparisons("3 + 7 &lt; 3 * 7 &lt;= 100");
  assert_string_equal("3 + 7 < 3 * 7 <= 100", result);
  free(result);
}

void test_mixed(void) {
  char* result = restore_comparisons("n&lt;&lt;nxplnd&gt; lp&gt;nt!");
  assert_string_equal("n<<nxplnd> lp>nt!", result);
  free(result);
}

int main(int argc, char* argv[]) {
  UnitTest tests[] = {
    unit_test(test_empty_str),
    unit_test(test_no_comparisons),
    unit_test(test_only_comparisons),
    unit_test(test_arithmetic),
    unit_test(test_mixed),
  };
  return run_tests(tests);
}
