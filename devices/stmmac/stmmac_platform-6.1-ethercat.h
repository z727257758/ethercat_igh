/* SPDX-License-Identifier: GPL-2.0-only */
/*******************************************************************************
  Copyright (C) 2007-2009  STMicroelectronics Ltd


  Author: Giuseppe Cavallaro <peppe.cavallaro@st.com>
*******************************************************************************/

#ifndef __STMMAC_PLATFORM_H__
#define __STMMAC_PLATFORM_H__

#include "stmmac-6.1-ethercat.h"

int stmmac_ec_dvr_probe(struct device *device,
			 struct plat_stmmacenet_data *plat_dat,
			 struct stmmac_resources *res);
int stmmac_ec_dvr_remove(struct device *dev);
int stmmac_suspend(struct device *dev);
int stmmac_resume(struct device *dev);
int ec_stmmac_bus_clks_config(struct stmmac_priv *priv, bool enabled);

#define ethercat_stmmac_dvr_probe stmmac_ec_dvr_probe
#define ethercat_stmmac_dvr_remove stmmac_ec_dvr_remove
#define ethercat_stmmac_suspend stmmac_suspend
#define ethercat_stmmac_resume stmmac_resume
#define ethercat_stmmac_bus_clks_config ec_stmmac_bus_clks_config

struct plat_stmmacenet_data *
ethercat_stmmac_probe_config_dt(struct platform_device *pdev, u8 *mac);
void ethercat_stmmac_remove_config_dt(struct platform_device *pdev,
			     struct plat_stmmacenet_data *plat);

int ethercat_stmmac_get_platform_resources(struct platform_device *pdev,
				  struct stmmac_resources *stmmac_res);

int ethercat_stmmac_pltfr_remove(struct platform_device *pdev);
extern const struct dev_pm_ops ethercat_stmmac_pltfr_pm_ops;

static inline void *get_stmmac_bsp_priv(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct stmmac_priv *priv = netdev_priv(ndev);

	return priv->plat->bsp_priv;
}

#endif /* __STMMAC_PLATFORM_H__ */
