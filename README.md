## A Singleton class for embedded systems

The Singleton class is designed to be subclassed by clients for use in embedded
systems without a dynamic memory allocator.  The typical use case is for
writing a class to represent a piece of hardware of which there can only be
one (e.g. a motor, sensor, or other piece of physical hardware).

To use the Singleton class, simply subclass it as follows:

    class SpecificSingleton : public Singleton<SpecificSingleton>
    {
     protected:
      SpecificSingleton() : someData_(42) {}
      ~SpecificSingleton() {}
     private:
      int someData_;
    };

and then you can get a reference to your singleton like this:

    SpecificSingleton & a = SpecificSingleton::Instance();

The class is implemented as headers only, so to use it simply add `Singleton.h`
and `Singleton_priv.h` to the include path of your project.  No libraries need
to be built or installed.  `make install` will install these headers to your
system.

That's all there is to it!

## Cloning and running tests

A couple of simple tests are implemented with
[googletest](http://code.google.com/p/googletest/ "Google C++ Testing
Framework").  For some reason googletest still uses subversion, so I had to
monkey around a bit in order to make googletest into a git submodule.  I
basically followed the advice given
[here](http://stackoverflow.com/questions/465042/is-it-possible-to-have-a-subversion-repository-as-a-git-submodule
"Is it possible to have a subversion repository as a git submodule?").  In
order to clone and build the Singleton repository, repeat the following
incantation

    $ git clone git://github.com/hazelnusse/Singleton.git
    $ cd Singleton
    $ git submodule init
    $ git submodule update
    $ mkdir build
    $ cd build
    $ cmake ..              # or: cmake-gui ..
    $ make                  # doesn't do anything if you disabled tests
    $ make test             # doesn't do anything if you disabled tests
    $ make install          # installs headers to /usr/local/include by default

## TODO
 * Make Singleton constructor allow for finite numbers of unique Singletons.
   For example, if you have two physical pieces of hardware, it would be useful
   to be able to do
   
       SpecificSingleton & a = SpecificSingleton::Instance(0);
       SpecificSingleton & b = SpecificSingleton::Instance(1);

   It might be useful to allow extra arguments to the Instance() method, in
   which case variadic templates might work.
