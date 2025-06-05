use tao::{
    event::{Event, StartCause, WindowEvent},
    event_loop::{ControlFlow, EventLoop},
    window::WindowBuilder,
};
use wry::WebViewBuilder;

fn main() -> wry::Result<()> {
    let event_loop = EventLoop::new();
    let window = WindowBuilder::new()
        .build(&event_loop)
        .expect("🪟 Failed to create window");

    let html_path = std::env::current_dir()?
        .join("frontend")
        .join("dist")
        .join("index.html");
    let url = format!("file://{}", html_path.display());

    let _webview = WebViewBuilder::new()
        .with_url(&url)
        .with_initialization_script(
            r#"
            document.title = 'Taku IDE';
            console.log('🌐 Wry is alive!');
        "#,
        )
        .build(&window)?;

    event_loop.run(move |event, _, control_flow| {
        *control_flow = ControlFlow::Wait;

        match event {
            Event::NewEvents(StartCause::Init) => println!("🌀 App started."),
            Event::WindowEvent {
                event: WindowEvent::CloseRequested,
                ..
            } => {
                println!("👋 Exiting...");
                *control_flow = ControlFlow::Exit;
            }
            _ => (),
        }
    });
}
