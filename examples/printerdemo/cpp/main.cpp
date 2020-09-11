/* LICENSE BEGIN
    This file is part of the SixtyFPS Project -- https://sixtyfps.io
    Copyright (c) 2020 Olivier Goffart <olivier.goffart@sixtyfps.io>
    Copyright (c) 2020 Simon Hausmann <simon.hausmann@sixtyfps.io>

    SPDX-License-Identifier: GPL-3.0-only
    This file is also available under commercial licensing terms.
    Please contact info@sixtyfps.io for more information.
LICENSE END */
#include "printerdemo.h"

// FIXME: Ideally it should be a better type in the generated code
using InkData = std::tuple<sixtyfps::Color, float>;

struct InkLevelModel : sixtyfps::Model<InkData>
{
    int count() const override { return m_data.size(); }
    InkData get(int i) const override { return m_data[i]; }

    std::vector<InkData> m_data = { { sixtyfps::Color::from_rgb_uint8(255, 255, 0), 0.9 },
                                    { sixtyfps::Color::from_rgb_uint8(0, 255, 255), 0.5 },
                                    { sixtyfps::Color::from_rgb_uint8(255, 0, 255), 0.8 },
                                    { sixtyfps::Color::from_rgb_uint8(0, 0, 0), 0.1 } };
};

int main()
{
    static MainWindow printer_demo;
    printer_demo.set_ink_levels(std::make_shared<InkLevelModel>());
    printer_demo.run();
}
