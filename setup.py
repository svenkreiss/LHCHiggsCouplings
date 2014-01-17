from distutils.core import setup
 
setup(
    name='LHCHiggsCouplings',
    version='1.1.0',
    packages=['LHCHiggsCouplings'],
    license='LICENSE',
    description='Python interface to the numbers published by the LHC Higgs Cross Section Working Group in Yellow Report 3.',
    long_description=open('README.md').read(),
    author='Sven Kreiss, Kyle Cranmer',
    author_email='sk@svenkreiss.com',
    install_requires=['numpy'],
    
    package_data={
        "": ["LICENSE"],
        "LHCHiggsCouplings": [
            'Higgs-coupling-data/*.txt',
            'Higgs-coupling-data/sm/br/*.txt',
            'Higgs-coupling-data/sm/xs/14TeV/*.txt',
            'Higgs-coupling-data/sm/xs/8TeV/*.txt',
            'Higgs-coupling-data/sm/xs/7TeV/*.txt',
        ]
    },
    include_package_data=True,
)
