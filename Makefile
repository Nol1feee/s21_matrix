CC = gcc
LCHECK = -lchek

ifeq ($(shell uname -p), arm)
	CC = gcc-12
	LCHECK = $(shell pkg-config --cflags --libs check)
endif

FLAGS = #-Wall -Wextra -Werror -std=c11 -pedantic

LIB = s21_matrix.a

OBJ = $(patsubst %.c, $(BUILD_OBJ_DIR)/%.o, $(wildcard *.c))

BUILD_OBJ_DIR = build_obj
TESTS_DIR = tests
EXECT_TEST = kek.c
all: $(LIB)

test: $(OBJ)
# ниже тупо
	$(shell checkmk $(TESTS_DIR)/s21_test.c > $(TESTS_DIR)/kek.c)
	$(CC) $(FLAGS) -c s21_common/s21_check.c -o $(BUILD_OBJ_DIR)/s21_check.o
	$(CC) $(LCHECK) -c $(TESTS_DIR)/$(EXECT_TEST) -o $(BUILD_OBJ_DIR)/kek.o
	$(CC) $(LCHECK) build_obj/s21_create_matrix.o build_obj/kek.o build_obj/s21_remove_matrix.o build_obj/s21_sum_matrix.o build_obj/s21_check.o build_obj/s21_eq_matrix.o build_obj/s21_sub_matrix.o build_obj/s21_mult_number.o build_obj/s21_transpose.o build_obj/s21_calc_complements.o build_obj/s21_determinant.o build_obj/s21_inverse_matrix.o -o testing
	#$(CC) $(LCHECK) $^ -o testing
# выше тупо
	./testing

$(BUILD_OBJ_DIR)/%.o : %.c
	@mkdir -p $(BUILD_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB): $(OBJ)
	$(CC) $(FLAGS) -c s21_common/s21_check.c -o $(BUILD_OBJ_DIR)/s21_check.o
	ar -rcs $@ $^ $(BUILD_OBJ_DIR)/s21_check.o

#ниже тупо
gcov_report: rebuild
	@$(CC) --coverage *.c s21_common/*.c tests/kek.c $(LCHECK) -lm -lpthread
	@./a.out
	@lcov -t "a.out" -o test.info -c -d .
	@genhtml -o report test.info
	@open report/index.html
	@mkdir -p build_for_tests
	@mv *.gcno *.gcda build_for_tests/
#выше тупо


rebuild: clean test

clean:
	@echo WAIT A SEC, MAN!!!
	@rm -rf $(LIB)
	@rm -rf $(BUILD_OBJ_DIR)
	@rm -rf $(TESTS_DIR)/*.o $(TESTS_DIR)/*.gcno build_for_tests
	@rm -rf *.o *.gcno a.out *.a *.txt  *.gcda *.info
	@rm -rf report
	@rm -rf tests/kek.c
	@echo REMOVING............
	@echo THANKS, I REMOVED ALL!