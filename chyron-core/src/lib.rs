use std::ffi::c_void;

type OnEventCallback = unsafe extern "C" fn() -> c_void;
static mut EVENT_CALLBACK: Option<OnEventCallback> = None;

#[no_mangle]
pub extern "C" fn chyron_initialize() {
    println!("Test from Rust");
    unsafe {
        if let Some(cb) = EVENT_CALLBACK {
            cb();
        }
    }
}

#[no_mangle]
pub extern "C" fn chyron_register_callback(cb: OnEventCallback) {
    unsafe {
        EVENT_CALLBACK = Some(cb);
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        let result = 2 + 2;
        assert_eq!(result, 4);
    }
}
