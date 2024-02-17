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
  // type si
  let a: [i32; 5] = [1, 2, 3, 4, 5];
}