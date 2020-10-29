void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor);
				XRDB_LOAD_COLOR("dwm.normbgcolor", normbgcolor);
				XRDB_LOAD_COLOR("dwm.normbordercolor", normbordercolor);
				XRDB_LOAD_COLOR("dwm.normfloatcolor", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.selfgcolor", selfgcolor);
				XRDB_LOAD_COLOR("dwm.selbgcolor", selbgcolor);
				XRDB_LOAD_COLOR("dwm.selbordercolor", selbordercolor);
				XRDB_LOAD_COLOR("dwm.selfloatcolor", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.titlenormfgcolor", normfgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbgcolor", normbgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbordercolor", normbordercolor);
				XRDB_LOAD_COLOR("dwm.titlenormfloatcolor", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.titleselfgcolor", selfgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbgcolor", selbgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbordercolor", selbordercolor);
				XRDB_LOAD_COLOR("dwm.titleselfloatcolor", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfgcolor", normfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbgcolor", normbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbordercolor", normbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfloatcolor", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsselfgcolor", selfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbgcolor", selbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbordercolor", selbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsselfloatcolor", selfloatcolor);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		alphas[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}
