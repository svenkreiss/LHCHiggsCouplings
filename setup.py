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
)
