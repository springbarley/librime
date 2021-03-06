//
// Copyleft 2011 RIME Developers
// License: GPLv3
//
// 2011-04-24 GONG Chen <chen.sst@gmail.com>
//
#ifndef RIME_SCHEMA_H_
#define RIME_SCHEMA_H_

#include <string>
#include <rime/common.h>
#include <rime/config.h>

namespace rime {

class Schema {
 public:
  Schema();
  explicit Schema(const std::string &schema_id);
  Schema(const std::string &schema_id, Config *config)
      : schema_id_(schema_id), config_(config) {}

  const std::string& schema_id() const { return schema_id_; }
  const std::string& schema_name() const { return schema_name_; }

  Config* config() const { return config_.get(); }
  void set_config(Config *config) { config_.reset(config); }

  int page_size() const { return page_size_; }
  const std::string& select_keys() const { return select_keys_; }
  void set_select_keys(const std::string& keys) { select_keys_ = keys; }

 private:
  void FetchUsefulConfigItems();

  std::string schema_id_;
  std::string schema_name_;
  scoped_ptr<Config> config_;
  // frequently used config items
  int page_size_;
  std::string select_keys_;
};

struct Ticket {
  Schema* schema;
  std::string name_space;

  Ticket(Schema* a_schema, const std::string& a_name_space)
      : schema(a_schema), name_space(a_name_space) {}
};

}  // namespace rime

#endif  // RIME_SCHEMA_H_
