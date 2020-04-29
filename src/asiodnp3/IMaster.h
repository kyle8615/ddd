#ifndef PYDNP3_ASIODNP3_IMASTER_H
#define PYDNP3_ASIODNP3_IMASTER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IMaster.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class IMaster.
*/
class PyIMaster : public IMaster {
  /* Inherit the constructors */
  using IMaster::IMaster;

  /* Trampoline for IMasterOperations virtual functions */
  void SetLogFilters(const openpal::LogFilters& filters) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        SetLogFilters,
        filters);
  }
  std::shared_ptr<IMasterScan> AddScan(openpal::TimeDuration period,
      const std::vector<opendnp3::Header>& headers,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMasterScan>,
        IMaster,
        AddScan,
        period, headers, config);
  }
  std::shared_ptr<IMasterScan> AddAllObjectsScan(opendnp3::GroupVariationID gvId,
      openpal::TimeDuration period,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMasterScan>,
        IMaster,
        AddAllObjectsScan,
        gvId, period, config);
  }
  std::shared_ptr<IMasterScan> AddClassScan(const opendnp3::ClassField& field,
      openpal::TimeDuration period,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMasterScan>,
        IMaster,
        AddClassScan,
        field, period, config);
  }
  std::shared_ptr<IMasterScan> AddRangeScan(opendnp3::GroupVariationID gvId,
      uint16_t start,
      uint16_t stop,
      openpal::TimeDuration period,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMasterScan>,
        IMaster,
        AddRangeScan,
        gvId, start, stop, period, config);
  }
  void Scan(const std::vector<opendnp3::Header>& headers,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        Scan,
        headers, config);
  }
  void ScanAllObjects(opendnp3::GroupVariationID gvId,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        ScanAllObjects,
        gvId, config);
  }
  void ScanClasses(const opendnp3::ClassField& field,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        ScanClasses,
        field, config);
  }
  void ScanRange(opendnp3::GroupVariationID gvId,
      uint16_t start,
      uint16_t stop,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        ScanRange,
        gvId, start, stop, config);
  }
  void Write(const opendnp3::TimeAndInterval& value,
      uint16_t index,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        Write,
        value, index, config);
  }
  void Restart(opendnp3::RestartType op,
      const opendnp3::RestartOperationCallbackT& callback,
      opendnp3::TaskConfig config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        Restart,
        op, callback, config);
  }
  void PerformFunction(const std::string& name,
      opendnp3::FunctionCode func,
      const std::vector<opendnp3::Header>& headers,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        PerformFunction,
        name, func, headers, config);
  }

  /* Trampoline for ICommandProcessor virtual functions */
  void SelectAndOperate(opendnp3::CommandSet&& commands,
      const opendnp3::CommandCallbackT& callback,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        SelectAndOperate,
        commands, callback, config);
  }
  void DirectOperate(opendnp3::CommandSet&& commands,
      const opendnp3::CommandCallbackT& callback,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        DirectOperate,
        commands, callback, config);
  }
  template <class T>
  void SelectAndOperate(const T& command,
      uint16_t index,
      const opendnp3::CommandCallbackT& callback,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default())
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        SelectAndOperate,
        command, index, callback, config);
  }
  template <class T>
  void DirectOperate(const T& command,
      uint16_t index,
      const opendnp3::CommandCallbackT& callback,
      const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default())
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        DirectOperate,
        command, index, callback, config);
  }

  /* Trampoline for IStack virtual functions */
  bool Enable() override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IMaster,
        Enable, );
  }
  bool Disable() override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IMaster,
        Disable, );
  }
  opendnp3::StackStatistics GetStackStatistics() override
  {
    PYBIND11_OVERLOAD_PURE(
        opendnp3::StackStatistics,
        IMaster,
        GetStackStatistics, );
  }

  /* Trampoline for IResource virtual functions */
  void Shutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMaster,
        Shutdown, );
  }
};
}

void bind_IMaster(py::module& m)
{
  // ----- class: asiodnp3::IMaster -----
  py::class_<asiodnp3::IMaster,
      asiodnp3::PyIMaster,
      asiodnp3::IMasterOperations,
      asiodnp3::IStack,
      std::shared_ptr<asiodnp3::IMaster>>(m, "IMaster",
      "Interface that represents a running master session.")

      .def(py::init<>());
}

#endif // PYDNP3_ASIODNP3
#endif
