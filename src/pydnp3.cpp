#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

#include <map>

namespace py = pybind11;

typedef std::function<py::module&(std::string const &)> ModuleGetter;

// Split pydnp3 into multiple compilation units to reduce memory requirements
void init_openpal(py::module &);
void init_opendnp3(py::module &);
void init_asiopal(py::module &);
void init_asiodnp3(py::module &);

PYBIND11_MODULE(pydnp3, root_module) {

    // -------------------- SET-UP --------------------
    root_module.doc() = "Python bindings for opendnp3 library";

    std::map<std::string, py::module> modules = {
        {"asiodnp3", root_module.def_submodule("asiodnp3", "Bindings for asiodnp3 namespace")},
        {"asiopal",  root_module.def_submodule("asiopal",  "Bindings for asiopal namespace")},
        {"opendnp3", root_module.def_submodule("opendnp3", "Bindings for opendnp3 namespace")},
        {"openpal",  root_module.def_submodule("openpal",  "Bindings for openpal namespace")}
    };

    ModuleGetter M = [&](std::string const &namespace_) -> py::module&
    {
        return (modules.find(namespace_))->second;
    };

    // -------------------- PYDNP3.OPENPAL --------------------
    py::module openpal = M("openpal");
    init_openpal(openpal);

    // -------------------- PYDNP3.OPENDNP3 --------------------
    py::module opendnp3 = M("opendnp3");
    init_opendnp3(opendnp3);

    // -------------------- PYDNP3.ASIOPAL --------------------
    py::module asiopal = M("asiopal");
    init_asiopal(asiopal);

    // -------------------- PYDNP3.ASIODNP3 --------------------
    py::module asiodnp3 = M("asiodnp3");
    init_asiodnp3(asiodnp3);
}
