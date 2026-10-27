# Simple System Resources

**Live resource readings, right on your Windows taskbar.**

Simple System Resources adds compact CPU, Memory, GPU and network readings to the taskbar. Click a pill to open a native flyout with a live graph and more details.

## Features

- **CPU, Memory and GPU readings** with live taskbar graphs and detailed flyouts.
- **Upload and Download speeds** shown side by side. Both network pills open the same Network flyout.
- **Individual or grouped pills**, with controls for which resources appear and where they sit on the taskbar. Drag the resource list in settings to choose the pill order; Upload and Download stay together.
- **Themes and appearance options**, including icon or name identifiers, optional resource names, graph styles, sizing and spacing.
- **Primary and secondary taskbar support**, with independently selectable placement for secondary taskbars.
- **Click to open**, or optionally open a flyout after hovering over a pill.
- **Top processes and a Task Manager link** in resource flyouts where applicable.

## Screenshots

### Resource flyouts

| CPU | Memory |
|:---:|:---:|
| ![CPU flyout](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-CPU-Flyout.png) | ![Memory flyout](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-RAM-Flyout.png) |

| GPU | Network |
|:---:|:---:|
| ![GPU flyout](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-GPU-Flyout.png) | ![Network flyout](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-LAN-Flyout.png) |

### Taskbar pill layouts

The descriptions below use `<br>` to put the copy on two lines. The table columns are left-aligned, so each screenshot starts at the left edge of its cell.

| Layout | Preview |
|:---|:---|
| **Individual pills · Background graph**<br>Each resource has its own pill, with activity shown behind the value. | ![Individual pills with background graphs](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-TaskbarPills-BackgroundGraph.png) |
| **Grouped pill · Background graph**<br>Resources share one pill, with a background graph for each reading. | ![Grouped pill with background graphs](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-TaskbarGrouped-BackgroundGraph.png) |
| **Individual pills · Boxed graph**<br>Each resource has its own pill and a separate, compact graph. | ![Individual pills with boxed graphs](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-TaskbarPills-BoxedGraph.png) |
| **Grouped pill · Boxed graph**<br>Resources share one pill, with compact graphs beside their readings. | ![Grouped pill with boxed graphs](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-TaskbarGrouped-BoxedGraph.png) |

## Getting started

1. Install **Windhawk** and install Simple System Resources from the mod store when available. During development, load the mod locally through Windhawk.
2. In **General**, choose which resources to show, the theme and the main taskbar position. Enabling Network adds both Upload and Download pills.
3. In **Taskbar pill**, choose individual or grouped layout, identifiers, graph style and appearance.
4. Click a pill to open its flyout. To use hover, enable **Open on hover** in **Flyout** and adjust the opening delay.

## Settings at a glance

- **General:** Resources, network speed units, theme, automatic light/dark theme and main taskbar placement.
- **Taskbar pill:** Monitor visibility, secondary taskbar placement, layout and resource order, content, appearance, typography, icons and graphs.
- **Flyout:** Hover behavior, animation, spacing from the taskbar and screen edge, size, graph height and top process count.
- **Theme color overrides:** Optional shared background, text, accent and muted colors for pills and flyouts.

## Notes

- Designed for the Windows 11 x64 Explorer taskbar. The taskbar layout is based on native Windows XAML.
- Readings are collected locally from Windows performance and network counters. The mod does not require an account or an internet connection.
- Network speed uses an automatically selected eligible Ethernet or Wi-Fi adapter. GPU readings use the selected hardware adapter; manual multi-GPU selection is not currently available.
- For deeper system controls and process details, open Task Manager from a flyout.

## Credits

- An independent community mod for [Windhawk](https://windhawk.net).
- Resource icon glyphs are based on Microsoft's PowerToys Performance Monitor.
- Taskbar layout techniques are adapted from [Mawaqit Prayer Clock](https://github.com/hheitlager/windhawk-mawaqit), by the same author.

## License

MIT License.

This is an unofficial community project and is not affiliated with or endorsed by Microsoft or PowerToys.
