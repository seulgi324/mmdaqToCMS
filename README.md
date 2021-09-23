# mmdaqToCMS
Read a rootfile produced with mmdaq and generate a new rootfile "output.root" compatible with the CMS GEM Analysis Framework

# Installation
To compile the code use:
```make```

# Running
The following command runs the code and utilize the provided ConfigFile.cfg:

```./Builder <mmdaq.root>```

The following command runs the code and utilize a custom (make sure it exists) MySpecialConfigFile.cfg:

```./Builder <mmdaq.root> <MySpecialConfigFile.cfg.```

# Considerations
[ConfigFile.Cfg](ConfigFile.cfg) is ready to use to my best knowledge, however it's easy to adjust it, follow the comments inside the configuration file to alter the detector geometry, Chip position and whatnot

The first time the code runs, it is slightly slower due to the ROOT runtime compiler, the second time it will run it will exploit a fully compiled code.

The code has been tested on a rootfile generated by mmdaq on lxplus.cern.ch 3.10.0-1160.36.2.el7.x86_64 #1 SMP, ROOT 6.24/04 and GCC 4.8.5 20150623 (Red Hat 4.8.5-44), GNU Make 3.82 Built for x86_64-redhat-linux-gnu

The code statically outputs the results into "output.root".
