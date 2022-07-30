/*
 *  Copyright © 2017-2022 Wellington Wallace
 *
 *  This file is part of EasyEffects.
 *
 *  EasyEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  EasyEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with EasyEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "maximizer_preset.hpp"

MaximizerPreset::MaximizerPreset(PresetType preset_type, const int& index) : PluginPresetBase(preset_type, index) {
  switch (preset_type) {
    case PresetType::input:
      settings = g_settings_new_with_path(tags::schema::maximizer::id, tags::schema::maximizer::input_path);
      break;
    case PresetType::output:
      settings = g_settings_new_with_path(tags::schema::maximizer::id, tags::schema::maximizer::output_path);
      break;
  }
}

void MaximizerPreset::save(nlohmann::json& json) {
  json[section]["maximizer"]["bypass"] = g_settings_get_boolean(settings, "bypass") != 0;

  json[section]["maximizer"]["input-gain"] = g_settings_get_double(settings, "input-gain");

  json[section]["maximizer"]["output-gain"] = g_settings_get_double(settings, "output-gain");

  json[section]["maximizer"]["release"] = g_settings_get_double(settings, "release");

  json[section]["maximizer"]["ceiling"] = g_settings_get_double(settings, "ceiling");

  json[section]["maximizer"]["threshold"] = g_settings_get_double(settings, "threshold");
}

void MaximizerPreset::load(const nlohmann::json& json) {
  update_key<bool>(json.at(section).at("maximizer"), settings, "bypass", "bypass");

  update_key<double>(json.at(section).at("maximizer"), settings, "input-gain", "input-gain");

  update_key<double>(json.at(section).at("maximizer"), settings, "output-gain", "output-gain");

  update_key<double>(json.at(section).at("maximizer"), settings, "release", "release");

  update_key<double>(json.at(section).at("maximizer"), settings, "ceiling", "ceiling");

  update_key<double>(json.at(section).at("maximizer"), settings, "threshold", "threshold");
}
