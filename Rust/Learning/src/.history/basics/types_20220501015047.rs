pub fn primitive(){
    println!("Primitive types!");
    // Underscored, otherwise Unused Variable warning
      // Variables can be type annotated.
    let _logical: bool = true;

    let _a_float: f64 = 1.0;  // Regular annotation
    let _an_integer   = 5i32; // Suffix annotation

    // Or a default will be used.
    let _default_float   = 3.0; // `f64`
    let _default_integer = 7;   // `i32`
    
    // A type can also be inferred from context 
    let mut _inferred_type = 12; // Type i64 is inferred from another line
    _inferred_type = 4294967296i64;
    
    // A mutable variable's value can be changed.
    let mut _mutable = 12; // Mutable `i32`
    _mutable = 21;
    
    // Error! The type of a variable can't be changed.
    // mutable = true;
    
    // Variables can be overwritten with shadowing.
    let _mutable = true;
}

pub fn tuple(){
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    // Destructure tup.
    let (_x, y, _z) = tup;
    println!("The value of y is: {}", y);

    //Inferred type
    let tup2 = (34, 45, 5);
    println!("The 3nd value i tup2 is: {}", tup2.2);
    //Print the entire tuple, but cannot do if too long
    println!("The entire tuple is: {:?}", tup2);
}

pub fn array(){
  // type signature is superfluous
  let a: [i32; 5] = [1, 2, 3, 4, 5];
  println!("The 3rd element of A is: {}", a[2]);

  let b = [1, 2, 3];
  println!("The entire array is: {:?}", b);
  println!("The length of the array is: {}", b.len());
}

pub fn structure(){
struct Person {
    name: String,
    age: u8,
}

// A unit struct, field-less
struct Unit;

// A tuple struct
struct Pair(i32, f32);

// A struct with two fields
struct Point {
    x: f32,
    y: f32,
}

// Structs can be reused as fields of another struct
struct Rectangle {
    // A rectangle can be specified by where the top left and bottom right
    // corners are in space.
    top_left: Point,
    bottom_right: Point,
  }

      // Create struct with field init shorthand
    let name = String::from("Peter");
    let age = 27;
    let peter = Person { name, age };

    // Print
    println!("{} is {} years old", peter.name, peter.age);

    // Instantiate a `Point`
    let point: Point = Point { x: 10.3, y: 0.4 };

    // Access the fields of the point
    println!("point coordinates: ({}, {})", point.x, point.y);
}

pub fn enumeration(){
// Create an `enum` to classify a web event. Note how both
// names and type information together specify the variant:
// `PageLoad != PageUnload` and `KeyPress(char) != Paste(String)`.
// Each is different and independent.
enum WebEvent {
    // An `enum` may either be `unit-like`,
    PageLoad,
    PageUnload,
    // like tuple structs,
    KeyPress(char),
    Paste(String),
    // or c-like structures.
    Click { x: i64, y: i64 },
}

// A function which takes a `WebEvent` enum as an argument and
// returns nothing.
fn inspect(event: WebEvent) {
    match event {
        WebEvent::PageLoad => println!("page loaded"),
        WebEvent::PageUnload => println!("page unloaded"),
        // Destructure `c` from inside the `enum`.
        WebEvent::KeyPress(c) => println!("pressed '{}'.", c),
        WebEvent::Paste(s) => println!("pasted \"{}\".", s),
        // Destructure `Click` into `x` and `y`.
        WebEvent::Click { x, y } => {
            println!("clicked at x={}, y={}.", x, y);
        },
    }
}

    let pressed = WebEvent::KeyPress('x');
    // `to_owned()` creates an owned `String` from a string slice.
    let pasted  = WebEvent::Paste("my text".to_owned());
    let click   = WebEvent::Click { x: 20, y: 80 };
    let load    = WebEvent::PageLoad;
    let unload  = WebEvent::PageUnload;

    inspect(pressed);
    inspect(pasted);
    inspect(click);
    inspect(load);
    inspect(unload);

}