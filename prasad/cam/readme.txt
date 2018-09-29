module int --> uvc_init() -->
usb_register(&uvc_driver.driver) -->

struct uvc_driver uvc_driver = {
.driver = {
	.name		= "uvcvideo",
	.probe		= uvc_probe,
	....
	},
};

static int uvc_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	/* Initialize controls. */
	if (uvc_ctrl_init_device(dev) < 0)
		goto error;

	/* Scan the device for video chains. */
	if (uvc_scan_device(dev) < 0)
		goto error;

	/* Register video devices. */
	if (uvc_register_chains(dev) < 0)
		goto error;

	/* Save our data pointer in the interface data. */
	usb_set_intfdata(intf, dev);
}

static int uvc_register_chains(struct uvc_device *dev)
{
	ret = uvc_register_terms(dev, chain);
}

static int uvc_register_terms(struct uvc_device *dev, struct uvc_video_chain *chain)
{
	ret = uvc_register_video(dev, stream)
}

static int uvc_register_video(struct uvc_device *dev, struct uvc_streaming *stream)
{
	....
	vdev->fops = &uvc_fops;
	....
}


