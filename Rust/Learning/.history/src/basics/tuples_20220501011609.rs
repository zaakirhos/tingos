pub fn tuple(){
    let tup: (i32, f64, u8) = (500, 6.4, 1);

    // Destructure tup. Underscore, otherwise warning error. 
    let (_x, y, _z) = tup;
    println!("The value of y is: {}", y);

    //Inferred type
    let tup2 = (34, 45, 5);
    println!("The 3nd value i tup2 is: {}", tup2.2);
}
pub fn f()