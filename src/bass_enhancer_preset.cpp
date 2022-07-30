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

#include "bass_enhancer_preset.hpp"

BassEnhancerPreset::BassEnhancerPreset(PresetType preset_type, const int& index)
    : PluginPresetBase(preset_type, index) {
  switch (preset_type) {
    case PresetType::input:
      settings = g_settings_new_with_path(tags::schema::bass_enhancer::id, tags::schema::bass_enhancer::input_path);
      break;
    case PresetType::output:
      settings = g_settings_new_with_path(tags::schema::bass_enhancer::id, tags::schema::bass_enhancer::output_path);
      break;
  }
}

void BassEnhancerPreset::save(nlohmann::json& json) {
  json[section]["bass_enhancer"]["bypass"] = g_settings_get_boolean(settings, "bypass") != 0;

  json[section]["bass_enhancer"]["input-gain"] = g_settings_get_double(settings, "input-gain");

  json[section]["bass_enhancer"]["output-gain"] = g_settings_get_double(settings, "output-gain");

  json[section]["bass_enhancer"]["amount"] = g_settings_get_double(settings, "amount");

  json[section]["bass_enhancer"]["harmonics"] = g_settings_get_double(settings, "harmonics");

  json[section]["bass_enhancer"]["scope"] = g_settings_get_double(settings, "scope");

  json[section]["bass_enhancer"]["floor"] = g_settings_get_double(settings, "floor");

  json[section]["bass_enhancer"]["blend"] = g_settings_get_double(settings, "blend");

  json[section]["bass_enhancer"]["floor-active"] = g_settings_get_boolean(settings, "floor-active") != 0;
}

void BassEnhancerPreset::load(const nlohmann::json& json) {
  update_key<bool>(json.at(section).at("bass_enhancer"), settings, "bypass", "bypass");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "input-gain", "input-gain");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "output-gain", "output-gain");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "amount", "amount");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "harmonics", "harmonics");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "scope", "scope");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "floor", "floor");

  update_key<double>(json.at(section).at("bass_enhancer"), settings, "blend", "blend");

  update_key<bool>(json.at(section).at("bass_enhancer"), settings, "floor-active", "floor-active");
}
