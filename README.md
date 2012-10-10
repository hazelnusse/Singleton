## A Singleton class for embedded systems

The Singleton class is designed to be subclassed by clients for use in embedded
systems without a dynamic memory allocator.  The typical use case is for
writing a class to represent a piece of hardware of which there can only be
one (e.g. a motor, sensor, or other piece of physical hardware).

To use the Singleton class, simply subclass it as follows:

    class SpecificSingleton : public Singleton<SpecificSingleton>
    {
     public:
      SpecificSingleton() : someData_(42) {}
      ~SpecificSingleton() {}
     private:
      int someData_;
    };

and then you can get a reference to your singleton like this:

    SpecificSingleton & a = SpecificSingleton::Instance();

That's all there is to it!

## TODO
 * Make Singleton constructor allow for finite numbers of unique Singletons.
   For example, if you have two physical pieces of hardware, it would be useful
   to be able to do
   
       SpecificSingleton & a = SpecificSingleton::Instance(0);
       SpecificSingleton & b = SpecificSingleton::Instance(1);

   It might be useful to allow extra arguments to the Instance() method, in
   which case variadic templates might work.
