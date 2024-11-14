#include <CLI/CLI.hpp>
#include <iostream>

int main(int argc, char** argv) {
    CLI::App app{"fnata"};

    CLI11_PARSE(app, argc, argv);

    return 0;
}
