# LHC Higgs Couplings

This package provides an interface to numbers produced by the LHC Higgs Cross Section Working Group (LHC HXSWG) for the Yellow Report 3 (YR3) with convenience functions like linear interpolation in m_H. A snapshot of the files in the HXSWG SVN is included in the module now; with permission from LHC HXSWG. 


# Tests

The default unittests can be run with [nose](http://nose.readthedocs.org/en/latest/) by running

```
make tests
```
in this directory.
 
To run a test by hand, run

```
import LHCHiggsCouplings
LHCHiggsCouplings.kH2(0.2,0.2,0.2,0.2)
```
in python and get back `0.039985238812654623`.



# Updating numbers from YR3

The numbers are included in this module and don't need to be touched for normal operation. But if you do want to update, SVN read access to svn.cern.ch/reps/lhchiggsxs/repository/Higgs-coupling/ is required.

The data can either reside in a local directory called `Higgs-coupling-data` inside this python module or somewhere on your filesystem and then the `HIGGSCOUPLINGDATA` environment variable needs to be set.

### Yellow Report 3 data in local directory (recommended)

From inside the LHCXSHiggsCouplings directory:

```
svn co https://svn.cern.ch/reps/lhchiggsxs/repository/Higgs-coupling/data Higgs-coupling-data
```

### Yellow Report 3 data somewhere else
To download the data into the subdirectory `Higgs-coupling-data` under the current directory and set the environment variable to tell this module where the data is:

```
svn co https://svn.cern.ch/reps/lhchiggsxs/repository/Higgs-coupling/data Higgs-coupling-data
export HIGGSCOUPLINGDATA=$PWD/Higgs-coupling-data
```


