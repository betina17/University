#include "Tests.h"
#include <assert.h>
#include <iostream>

void Tests::test_default_constructor() {
    TrenchCoat trench_coat;
    assert(trench_coat.get_price() == 0);
    assert(trench_coat.get_quantity() == 0);
    assert(trench_coat.get_size() == "");
    assert(trench_coat.get_colour() == "");
    assert(trench_coat.get_photograph() == "");
}

void Tests::test_parameterized_constructor() {
    TrenchCoat trench_coat("M", "Red", 100, 5, "path/to/photo.jpg");
    assert(trench_coat.get_price() == 100);
    assert(trench_coat.get_quantity() == 5);
    assert(trench_coat.get_size() == "M");
    assert(trench_coat.get_colour() == "Red");
    assert(trench_coat.get_photograph() == "path/to/photo.jpg");
}

void Tests::test_copy_constructor() {
    TrenchCoat original("M", "Red", 100, 5, "path/to/photo.jpg");
    TrenchCoat copy(original);
    assert(copy.get_price() == 100);
    assert(copy.get_quantity() == 5);
    assert(copy.get_size() == "M");
    assert(copy.get_colour() == "Red");
    assert(copy.get_photograph() == "path/to/photo.jpg");
}

void Tests::test_display_as_string() {
    TrenchCoat trench_coat("M", "Red", 100, 5, "path/to/photo.jpg");
    std::string expected_output = "\nThis trench coat comes in size M, colour Red at the price of 100 euros, the quantity is 5";
    assert(trench_coat.display_as_string() == expected_output);
}

void Tests::test_getters_and_setters() {
    TrenchCoat trench_coat;
    trench_coat.set_price(200);
    trench_coat.set_quantity(10);
    trench_coat.set_photograph("path/to/new_photo.jpg");

    assert(trench_coat.get_price() == 200);
    assert(trench_coat.get_quantity() == 10);
    assert(trench_coat.get_photograph() == "path/to/new_photo.jpg");

    trench_coat.ShowImage();
}

