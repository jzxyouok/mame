// license:BSD-3-Clause
// copyright-holders:AJR

#ifndef MAME_MACHINE_TV955KB_H
#define MAME_MACHINE_TV955KB_H

#pragma once

#include "cpu/mcs48/mcs48.h"
//#include "machine/ripple_counter.h"
//#include "sound/spkrdev.h"
//#include "speaker.h"


//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> tv955kb_device

class tv955kb_device : public device_t
{
public:
	tv955kb_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock = 0);

	// configuration
	auto txd_cb() { return m_txd_cb.bind(); }
	auto reset_cb() { return m_reset_cb.bind(); }

	DECLARE_WRITE_LINE_MEMBER(write_rxd);

	static constexpr feature_type unemulated_features() { return feature::SOUND; }

protected:
	// device-specific overrides
	virtual void device_resolve_objects() override;
	virtual void device_start() override;
	virtual void device_add_mconfig(machine_config &config) override;
	virtual ioport_constructor device_input_ports() const override;
	virtual const tiny_rom_entry *device_rom_region() const override;

private:
	u8 keys_r();
	DECLARE_WRITE_LINE_MEMBER(bell_w);
	DECLARE_WRITE_LINE_MEMBER(txd_w);
	DECLARE_WRITE_LINE_MEMBER(reset_w);

	// line output callbacks
	devcb_write_line m_txd_cb;
	devcb_write_line m_reset_cb;

	required_device<mcs48_cpu_device> m_mcu;
	required_ioport_array<16> m_keys;
};

// device type definition
DECLARE_DEVICE_TYPE(TV955_KEYBOARD, tv955kb_device)

#endif // MAME_MACHINE_TV955KB_H
