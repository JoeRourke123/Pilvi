#include <iostream>
#include "include/CLI11.hpp"

int main(int argc, char *argv[]) {
    int should_use_random_domain{0};
    std::string domain_value;
    std::string port_value;

    CLI::App app{"App description"};

    app.add_flag("-r,--random-domain", should_use_random_domain,
                 "If flag is applied, a random subdomain will be chosen");

    app.add_option(
            "-d,--domain",
            domain_value,
            "The domain or subdomain to point the reverse proxy to"
    )->check(
            [&should_use_random_domain](const std::string &val) {
                if (should_use_random_domain) {
                    return "Cannot use random and specified domains";
                } else return "";
            }, "Checks that both random and domain have not been specified");

    app.add_option(
            "-p,--port",
            port_value,
            "The port which should be reverse proxied"
    )->mandatory(true);

    CLI11_PARSE(app, argc, argv);


    return 0;
}
