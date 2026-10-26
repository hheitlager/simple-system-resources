// ==WindhawkMod==
// @id simple-system-resources
// @name Simple System Resources
// @description Taskbar resource pills with live CPU, RAM, GPU and network usage
// @version 0.1.0
// @author HHeitlager
// @github https://github.com/hheitlager
// @include explorer.exe
// @architecture x86-64
// @compilerOptions -ladvapi32 -DWIN32_LEAN_AND_MEAN -lole32 -loleaut32 -lruntimeobject -ldxgi -lpdh -liphlpapi -lws2_32 -lcomctl32
// @license MIT
// ==/WindhawkMod==
// Taskbar host access and layout lease adapted from Mawaqit Prayer Clock.
// Copyright (c) 2026 HHeitlager. MIT License.
// https://github.com/hheitlager/windhawk-mawaqit
// ==WindhawkModReadme==
/*
# Simple System Resources

## See your system at a glance.
Simple System Resources adds compact, live resource readings to the Windows 11
taskbar. Click a pill for a closer look with a live graph and useful details,
without opening Task Manager first.

## Features
- **CPU, Memory and GPU:** Keep usage visible and view a larger graph and details
  when you need them.
- **Network speed:** See Upload and Download side by side. Both pills open the
  same Network flyout with live rates and a combined graph.
- **Make it yours:** Choose which resources appear, individual or grouped pills,
  a theme, icons or names, and optional graphs.
- **Fits your taskbar:** Place the pills around the system tray, clock or taskbar
  icons. Primary and secondary taskbars can be configured separately.
- **Quick details:** Open a resource flyout by clicking its pill. Optional hover
  opening is off by default. Each flyout includes a link to Task Manager.

## Screenshots
![CPU flyout with the resource pills in the Windows taskbar](https://raw.githubusercontent.com/hheitlager/simple-system-resources/main/screenshots/Simple-System-Resources-CPU-Flyout.png)

## Getting Started
**1. Choose your resources**
In **Resources**, enable the readings you want. Network adds both Upload and
Download pills.

**2. Set up your taskbar**
Choose a taskbar position and layout, then pick a theme under **Style**.

**3. Open a resource**
Click a pill to see its graph and details. Upload and Download share one Network
flyout. If you prefer hover, enable **Open on hover** and adjust its delay.

## Good to Know
- **Windows 11 x64.** Uses Explorer's native XAML taskbar and supports primary
  and secondary monitors.
- **Your readings stay local.** The mod reads Windows performance and network
  counters on your PC. No account or internet connection is required.
- **Hardware data varies.** Network speed follows one automatically selected
  eligible Ethernet or Wi-Fi adapter. GPU readings use the selected hardware
  adapter; manual multi-GPU selection is not available yet.
- **A simple helper, with Task Manager nearby.** Process details and deeper
  system controls remain available in Task Manager.

## More Information
For source code and project updates, visit the [Simple System Resources repository](https://github.com/hheitlager/simple-system-resources).

## Credits and Acknowledgements
- Simple System Resources is an independent community project for [Windhawk](https://windhawk.net).
- Resource icon glyphs are based on Microsoft's PowerToys Performance Monitor.
- Taskbar layout support follows techniques developed for [Mawaqit Prayer Clock](https://github.com/hheitlager/windhawk-mawaqit), by the same author.

## License
MIT License.

## Disclaimer
This is an unofficial community project and is not affiliated with or endorsed
by Microsoft or PowerToys.
*/
// ==/WindhawkModReadme==
// ==WindhawkModSettings==
/*
- Resources:
  - showCpu: true
    $name: Show CPU usage
  - showRam: true
    $name: Show RAM usage
  - showGpu: true
    $name: Show GPU usage
  - showNetwork: false
    $name: Show Network speed
    $description: Shows both Upload and Download.
  - networkSpeedUnits: bits
    $name: Network speed units
    $options:
    - bits: Bits/s (Kbps, Mbps)
    - bytes: Bytes/s (KB/s, MB/s)
  $name: Resources
- Content:
  - resourceIdentifier: icon
    $name: Resource identifier
    $options:
    - icon: Icon
    - name: Name
    - none: None
  - showResourceNames: false
    $name: Show resource names
    $description: Adds a second row, except in Name identifier mode. The saved preference is preserved.
  - graphStyle: none
    $name: Graph style
    $options:
    - none: None
    - boxed: Boxed
    - background: Background
  $name: Content
- Flyout:
  - openOnHover: false
    $name: Open on hover
    $description: Resource flyouts, including the shared Network flyout. Click always opens them. The flyout stays open while you move into it; click outside or press Escape to close.
  - hoverDelay: 500
    $name: Hover opening delay (ms)
    $description: Keep the pointer over a pill for this long before opening (100–3000 ms). Passing over it cancels the wait. Click opens immediately.
  - hoverCloseDelay: 300
    $name: Hover closing delay (ms)
    $description: Time to cross the gap or return after leaving a hover-opened flyout (100–3000 ms). Click-opened flyouts keep normal dismissal behavior.
  - gap: 15
    $name: Gap from taskbar
    $description: Additional native flyout spacing in logical pixels (0–40). Default matches Mawaqit's floating popup spacing.
  - screenEdgeMargin: 10
    $name: Screen edge margin
    $description: Minimum outer spacing from the monitor work-area edges in logical pixels (0–100), scaled for DPI. The taskbar-facing edge uses Gap from taskbar instead.
  - animations: true
    $name: Flyout animations
    $description: Uses Windows native opening and closing animations.
  - width: 575
    $name: Width
    $description: Logical pixels (320–1000), limited to the monitor work area.
  - height: 400
    $name: Height
    $description: Preferred minimum in logical pixels (240–900). Grows to fit content and the selected process count, limited to the monitor work area. No scrollbar.
  - graphHeight: 100
    $name: Graph height
    $description: Logical pixels (80–400). Shared graph height for CPU, Memory and GPU flyouts.
  - topCount: 3
    $name: Number of top processes
    $description: 1–10 processes ranked by CPU usage, private working set or GPU usage, depending on the flyout. Protected or inaccessible processes are skipped.
  $name: Flyout
- Layout:
  - Monitors:
    - showPrimary: true
      $name: Show on primary taskbar
    - showSecondary: true
      $name: Show on secondary taskbars
      $description: Also choose a secondary position other than Hidden. Turning this off preserves your selected position.
    $name: Monitors
  - mainPosition: before-tray
    $name: Main taskbar position
    $options:
    - before-tray: Before system tray
    - before-clock: Before clock (inside system tray)
    - after-clock: After clock (inside system tray)
    - before-start: Before Windows Start
    - before-icons: Before taskbar icons
    - after-icons: After taskbar icons
    - center: Dynamic center (experimental)
  - secondaryPosition: hidden
    $name: Secondary taskbar position
    $description: Applies to every secondary monitor taskbar. Shares the main taskbar's resource readings and appearance.
    $options:
    - hidden: Hidden
    - follow-main: Follow main
    - before-tray: Before system tray
    - before-clock: Before clock (inside system tray)
    - after-clock: After clock (inside system tray)
    - before-start: Before Windows Start
    - before-icons: Before taskbar icons
    - after-icons: After taskbar icons
    - center: Dynamic center (experimental)
  - centerOffset: 0
    $name: Dynamic center offset
    $description: Horizontal logical pixels (-2000–2000). Shared across monitors. Dynamic center moves right for buttons and hides if it cannot fit.
  - layout: individual
    $name: Layout
    $options:
    - individual: Individual pills
    - grouped: Grouped pill
  - Dimensions:
    - resourceMinWidth: 65
      $name: CPU, RAM and GPU minimum width
      $description: Logical pixels (48–400), before adding a boxed graph. Content may require more space.
    - networkMinWidth: 92
      $name: Upload and Download minimum width
      $description: Logical pixels per direction (48–400), before adding a boxed graph.
    $name: Dimensions
  - Spacing:
    - padding: 8,0,8,0
      $name: Inner padding
      $description: Left,Top,Right,Bottom in logical pixels (0–64 each).
    - identifierGap: 7
      $name: Identifier-to-value gap
    - graphGap: 8
      $name: Gap before boxed graph
    - pillSpacing: 6
      $name: Spacing between individual pills
      $description: Ignored in grouped mode.
    - margin: 0,5,0,5
      $name: Outer margin
      $description: Left,Top,Right,Bottom in logical pixels (-100–100 each).
    $name: Spacing
  $name: Layout
- Style:
  - preset: current
    $name: Theme
    $options:
    - current: Current appearance
    - system: Windows / System
    - monochrome: Monochrome
    - catppuccin: Catppuccin Mocha
    - catppuccin-latte: Catppuccin Latte
    - emberveil: Emberveil
    - emberveil-midnight: Emberveil Midnight
    - emberveil-daybreak: Emberveil Daybreak
    - emerald: Emerald
    - dracula: Dracula
    - dracula-light: Dracula Light
    - nord: Nord
    - nord-light: Nord Light
    - gruvbox: Gruvbox Dark
    - gruvbox-light: Gruvbox Light
    - tokyo-night: Tokyo Night
    - tokyo-night-day: Tokyo Night Day
    - solarized-dark: Solarized Dark
    - solarized-light: Solarized Light
    - rose-pine: Rosé Pine
    - everforest: Everforest
    - synthwave-84: SynthWave '84
    - flexoki: Flexoki
    - kanagawa: Kanagawa
    - ayu: Ayu
    - one-dark: One Dark
    - custom: Custom
  - automaticTheme: false
    $name: Automatic light/dark theme
    $description: Switches established light/dark palette pairs with Windows taskbar mode. Windows/System and Monochrome always update live.
  - Background:
    - style: solid
      $name: Background style
      $options:
      - solid: Solid
      - transparent: Transparent
    - opacity: 100
      $name: Background opacity
      $description: Percentage (0–100). Only affects the Solid background; text, icons, borders and graphs retain their own opacity.
    $name: Background
  - Shape:
    - height: 0
      $name: Pill height
      $description: 0 = Auto (follows the styled taskbar height). Positive values set a manual height in logical pixels (up to 100).
    - cornerRadius: 12
      $name: Corner radius
      $description: Logical pixels. Limited to half the effective pill height.
    - borderEnabled: false
      $name: Show border
    - borderThickness: 1
      $name: Border thickness
      $description: Logical pixels (0–4).
    - borderOpacity: 20
      $name: Border opacity
      $description: Percentage (0–100). Applies to theme and custom border colours in both layouts.
    $name: Shape
  - Typography:
    - fontFamily: Segoe UI
      $name: Font family
    - valueSize: 11
      $name: Value font size
    - valueWeight: 600
      $name: Value font weight
      $description: 100–900; 400 is Normal, 600 is Semibold, 700 is Bold.
    - nameSize: 9
      $name: Second-row name font size
    - identifierSize: 11
      $name: Text identifier font size
    $name: Typography
  - Icons:
    - iconSize: 16
      $name: Icon size
      $description: Logical pixels (8–48).
    $name: Icons
  - Graphs:
    - width: 44
      $name: Box width
      $description: Logical pixels (16–240).
    - height: 18
      $name: Graph height
      $description: Logical pixels (4–100), limited to available content height.
    - lineThickness: '1.25'
      $name: Line thickness
      $description: Logical pixels (0.5–4); decimals supported.
    - fillOpacity: 19
      $name: Background fill opacity
      $description: Percentage (0–100).
    - backgroundLineOpacity: 25
      $name: Background line opacity
      $description: Percentage (0–100). Boxed graph lines remain fully opaque.
    $name: Graphs
  $name: Style
- Overrides:
  - background: ''
    $name: Background
  - border: ''
    $name: Border
  - identifier: ''
    $name: Identifier
  - value: ''
    $name: Value
  - name: ''
    $name: Second-row name
  - graph: ''
    $name: Graph
  $name: Theme colour overrides
  $description: Optional six-digit RGB colours, with or without "#"; surrounding whitespace is ignored. Empty or invalid values
    inherit the selected theme. Background graph fill uses the Graph colour and configured fill opacity.
*/
// ==/WindhawkModSettings==
// WIN32_LEAN_AND_MEAN applies before Windhawk's preincluded Windows header,
// avoiding legacy Winsock. Winsock 2 supplies ws2ipdef's socket types.
#include <winsock2.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <netioapi.h>
#include <windhawk_utils.h>
#include <algorithm>
#include <atomic>
#include <commctrl.h>
#include <cstdint>
#include <cmath>
#include <map>
#include <mutex>
#include <limits>
#include <array>
#include <deque>
#include <memory>
#include <vector>
#include <dxgi1_2.h>
#include <pdh.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <pdhmsg.h>
#include <cwchar>
#include <cwctype>
#include <string>
#include <utility>
#undef GetCurrentTime
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Text.h>
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;
namespace wf = winrt::Windows::Foundation;
namespace folder_menus_slot_lease
{

using winrt::Windows::UI::Xaml::FrameworkElement;
using winrt::Windows::UI::Xaml::GridUnitType;
using winrt::Windows::UI::Xaml::Controls::ColumnDefinition;
using winrt::Windows::UI::Xaml::Controls::Grid;
using winrt::Windows::UI::Xaml::Controls::Panel;
using winrt::Windows::UI::Xaml::Controls::StackPanel;

enum class Anchor
{
    BeforeIcons,
    AfterShowDesktop,
};

// Which layout contract the live tray panel follows.
enum class Kind
{
    Unsupported, // some other Panel: do not guess its layout semantics.
    Columns,     // Grid. A slot is a column index.
    Order,       // StackPanel. A slot is a child index.
};

struct Lease
{
    std::wstring markerName;
    int slot = -1;
    Kind kind = Kind::Unsupported;
    bool createdBaseColumn = false;
};

inline Kind Classify(FrameworkElement const& parent)
{
    if (!parent)
        return Kind::Unsupported;
    if (parent.try_as<Grid>())
        return Kind::Columns;
    if (parent.try_as<StackPanel>())
        return Kind::Order;
    return Kind::Unsupported;
}

inline FrameworkElement FindDirectChild(Panel const& parent, wchar_t const* name)
{
    if (!parent || !name)
        return nullptr;
    for (auto const& child : parent.Children())
    {
        auto element = child.try_as<FrameworkElement>();
        if (element && element.Name() == name)
            return element;
    }
    return nullptr;
}

inline int IndexOfChild(Panel const& parent, FrameworkElement const& child)
{
    if (!parent || !child)
        return -1;
    for (uint32_t i = 0; i < parent.Children().Size(); ++i)
    {
        if (parent.Children().GetAt(i).try_as<FrameworkElement>() == child)
            return static_cast<int>(i);
    }
    return -1;
}

inline bool Release(Panel const& parent, Lease& lease);

inline bool AcquireAt(Panel const& parent, int slot, std::wstring const& markerName, Lease& lease)
{
    Kind kind = Classify(parent);
    if (kind == Kind::Unsupported || slot < 0 || markerName.empty())
        return false;

    // A marker with this name already in the tray is either this caller's own
    // live lease — refuse, acquiring twice would strand the first slot — or a
    // leftover from an instance whose teardown never reached the UI thread.
    // Refusing the leftover would block every later apply until Explorer
    // restarts, so release it and take the slot fresh, correcting the
    // requested slot if the released one sat before it.
    if (auto stale = FindDirectChild(parent, markerName.c_str()))
    {
        if (lease.markerName == markerName)
            return false;
        int staleSlot =
            kind == Kind::Columns ? Grid::GetColumn(stale) : IndexOfChild(parent, stale);
        Lease leftover{markerName, staleSlot, kind};
        if (!Release(parent, leftover))
            return false;
        if (staleSlot >= 0 && staleSlot < slot)
            --slot;
    }

    Grid marker;
    marker.Name(markerName);
    marker.Width(0.0);
    marker.Height(0.0);
    marker.IsHitTestVisible(false);

    if (kind == Kind::Columns)
    {
        auto grid = parent.try_as<Grid>();
        if (!grid)
            return false;
        // A Grid without ColumnDefinitions uses one implicit full-width column.
        // Materialize that implicit column before inserting a lease column;
        // otherwise the repeater is shifted to column 1 in a ONE-column grid.
        bool createdBaseColumn = grid.ColumnDefinitions().Size() == 0;
        if (createdBaseColumn)
        {
            ColumnDefinition base;
            base.Width({1.0, GridUnitType::Star});
            grid.ColumnDefinitions().Append(base);
        }
        ColumnDefinition definition;
        definition.Width({1.0, GridUnitType::Auto});
        slot = std::min(slot, static_cast<int>(grid.ColumnDefinitions().Size()));
        if (static_cast<uint32_t>(slot) < grid.ColumnDefinitions().Size())
            grid.ColumnDefinitions().InsertAt(slot, definition);
        else
            grid.ColumnDefinitions().Append(definition);

        for (auto const& child : grid.Children())
        {
            auto element = child.try_as<FrameworkElement>();
            if (!element)
                continue;
            int start = Grid::GetColumn(element);
            int span = Grid::GetColumnSpan(element);
            if (start >= slot)
                Grid::SetColumn(element, start + 1);
            else if (start + span > slot)
                Grid::SetColumnSpan(element, span + 1);
        }

        Grid::SetColumn(marker, slot);
        grid.Children().Append(marker);
        lease.createdBaseColumn = createdBaseColumn;
    }
    else
    {
        // Order: no column is created or owned. The marker simply holds the
        // position, and PlaceChild drops the content next to it.
        uint32_t index = std::min(static_cast<uint32_t>(slot), parent.Children().Size());
        parent.Children().InsertAt(index, marker);
        slot = static_cast<int>(index);
    }

    lease = {markerName, slot, kind, lease.createdBaseColumn};
    return true;
}

// Live index of the lease marker. Other mods inject and remove siblings around
// us, so the acquire-time index is a hint, never the truth at removal time.
inline bool FindMarker(Panel const& parent, Lease const& lease, uint32_t& index)
{
    if (!parent || lease.markerName.empty())
        return false;
    for (uint32_t i = 0; i < parent.Children().Size(); ++i)
    {
        auto element = parent.Children().GetAt(i).try_as<FrameworkElement>();
        if (element && element.Name() == lease.markerName)
        {
            index = i;
            return true;
        }
    }
    return false;
}

// Put mod content into the leased slot. On a Grid the content joins the leased
// column; on a StackPanel it is inserted directly after the marker, so the
// marker's position is the content's position.
inline bool PlaceChild(Panel const& parent, Lease const& lease, FrameworkElement const& content)
{
    if (!parent || !content || lease.kind == Kind::Unsupported)
        return false;

    uint32_t markerIndex = 0;
    if (!FindMarker(parent, lease, markerIndex))
        return false;

    if (lease.kind == Kind::Columns)
    {
        auto marker = parent.Children().GetAt(markerIndex).try_as<FrameworkElement>();
        Grid::SetColumn(content, marker ? Grid::GetColumn(marker) : lease.slot);
        parent.Children().Append(content);
        return true;
    }

    parent.Children().InsertAt(markerIndex + 1, content);
    return true;
}

inline bool Release(Panel const& parent, Lease& lease)
{
    if (!parent || lease.markerName.empty())
        return false;

    uint32_t markerIndex = 0;
    if (!FindMarker(parent, lease, markerIndex))
        return false;

    if (lease.kind == Kind::Order)
    {
        parent.Children().RemoveAt(markerIndex);
        lease = {};
        return true;
    }

    auto grid = parent.try_as<Grid>();
    auto marker = parent.Children().GetAt(markerIndex).try_as<FrameworkElement>();
    int liveColumn = marker ? Grid::GetColumn(marker) : lease.slot;
    if (!grid || liveColumn < 0)
        return false;

    grid.Children().RemoveAt(markerIndex);
    if (static_cast<uint32_t>(liveColumn) < grid.ColumnDefinitions().Size())
        grid.ColumnDefinitions().RemoveAt(liveColumn);

    for (auto const& child : grid.Children())
    {
        auto element = child.try_as<FrameworkElement>();
        if (!element)
            continue;
        int start = Grid::GetColumn(element);
        int span = Grid::GetColumnSpan(element);
        if (start > liveColumn)
            Grid::SetColumn(element, start - 1);
        else if (start < liveColumn && start + span > liveColumn)
            Grid::SetColumnSpan(element, std::max(1, span - 1));
    }

    // Restore the original implicit-column layout only for columns we created.
    if (lease.createdBaseColumn && grid.ColumnDefinitions().Size() == 1)
        grid.ColumnDefinitions().Clear();
    lease = {};
    return true;
}

} // namespace folder_menus_slot_lease
namespace slot = folder_menus_slot_lease;
std::atomic<bool> stopping{false};
HANDLE stopEvent = nullptr, startupWorker = nullptr;
std::atomic<bool> showCpu{false}, showRam{false}, showGpu{false}, showNetwork{false};
std::atomic<bool> networkBits{true}, groupedLayout{false};
std::atomic<int> resourceMinWidth{65}, networkMinWidth{92};
enum class GraphStyle { None, Boxed, Background };
std::atomic<GraphStyle> graphStyle{GraphStyle::None};
enum class ResourceIdentifier { Icon, Name, None };
std::atomic<ResourceIdentifier> resourceIdentifier{ResourceIdentifier::Icon};
std::atomic<bool> showResourceNames{false};
std::atomic<bool> flyoutOnHover{false}, flyoutAnimations{true};
std::atomic<int> flyoutGap{11}, flyoutScreenMargin{11}, hoverDelay{500}, hoverCloseDelay{300};
std::atomic<int> flyoutWidth{575}, flyoutHeight{400}, flyoutGraphHeight{100}, flyoutTopCount{3};
GraphStyle StyleFor(unsigned) { return graphStyle.load(); }
// Plain appearance data is published as one snapshot. XAML objects stay on UI thread.
struct AppearanceConfig {
    std::wstring font = L"Segoe UI";
    double height = 0, radius = 12, border = 0;
    double valueSize = 11, nameSize = 9, identifierSize = 11, iconSize = 16;
    int valueWeight = 600;
    double graphWidth = 44, graphHeight = 18, graphGap = 8, stroke = 1.25;
    BYTE fillAlpha = 48, backgroundLineAlpha = 64;
    double borderOpacity = 0.20;
    bool solidBackground = true;
    double backgroundOpacity = 1;
    Thickness padding{8, 0, 8, 0}, margin{0, 5, 0, 5};
    double identifierGap = 7, pillSpacing = 6;
    winrt::Windows::UI::Color background{255, 0x21, 0x1E, 0x32};
    winrt::Windows::UI::Color borderColor{255, 180, 190, 254};
    winrt::Windows::UI::Color identifierColor{255, 240, 238, 246};
    winrt::Windows::UI::Color valueColor{255, 240, 238, 246};
    winrt::Windows::UI::Color nameColor{255, 240, 238, 246};
    winrt::Windows::UI::Color graphColor{255, 180, 190, 254};
    unsigned revision = 0;
};
SRWLOCK appearanceLock = SRWLOCK_INIT;
AppearanceConfig appearanceConfig;
AppearanceConfig GetAppearance() {
    AcquireSRWLockShared(&appearanceLock);
    auto value = appearanceConfig;
    ReleaseSRWLockShared(&appearanceLock);
    return value;
}

// Plain, independently testable hover intent. All transitions run on the owning UI thread.
enum class HoverAction { None, Open, Close };
struct ResourceHoverState {
    bool overPill = false, overFlyout = false, pending = false, hoverOpened = false;
    bool opening = false;
    uint64_t entered = 0, outside = 0, requested = 0;
    bool earlyCloseGuardUsed = false;
    uint64_t pillClickUntil = 0;
    bool pillClickPins = false, pillTapConsumed = false;
    int32_t pillClickMessage = 0;
    void RememberPillClick(uint64_t now, bool pins, int32_t message = 0) {
        pillClickMessage = message;
        pillClickUntil = now + 600;
        pillClickPins = pins;
        pillTapConsumed = false;
    }
    bool ConsumeHandledTap(uint64_t now) {
        if (!pillClickUntil || now > pillClickUntil || pillTapConsumed) return false;
        pillTapConsumed = true;
        return true;
    }
    void Enter(uint64_t now) {
        overPill = true; outside = 0;
        if (!hoverOpened) { pending = true; entered = now; }
    }
    void Leave(uint64_t now) {
        overPill = false; pending = false;
        if (!overFlyout) outside = now;
    }
    void FlyoutPointer(bool inside, uint64_t now) {
        overFlyout = inside;
        if (inside) outside = 0;
        else if (!overPill) outside = now;
    }
    bool GuardEarlyClose(uint64_t now, bool cursorOverPill, bool userInput, bool unloading) {
        if (unloading || userInput || !cursorOverPill || !hoverOpened || !opening ||
            earlyCloseGuardUsed || now < requested || now - requested >= 500) return false;
        earlyCloseGuardUsed = true;
        return true;
    }
    void Presented(uint64_t now) {
        opening = false;
        if (hoverOpened && !overPill && !overFlyout) outside = now;
    }
    void Dismiss() { pending = false; hoverOpened = false; opening = false; outside = 0; }
    HoverAction Tick(uint64_t now, unsigned openDelay, unsigned closeDelay) {
        if (pending && overPill && now - entered >= openDelay) {
            pending = false; hoverOpened = true; opening = true; requested = now; earlyCloseGuardUsed = false;
            return HoverAction::Open;
        }
        if (hoverOpened && !opening && !overPill && !overFlyout && outside && now - outside >= closeDelay) {
            Dismiss(); return HoverAction::Close;
        }
        return HoverAction::None;
    }
};

// Only weak XAML references survive a UI operation; no apartment-bound globals.
struct PillInstance {
    std::array<ResourceHoverState, 5> hover;
    bool hoverSubclass = false, hoverTimer = false;
    HWND hwnd = nullptr;
    winrt::weak_ref<Panel> parent;
    winrt::weak_ref<StackPanel> group;
    winrt::weak_ref<Border> surface;
    winrt::weak_ref<Viewbox> host;
    slot::Lease lease;
    int position = -99;
    unsigned appliedRevision = 0;
    double appliedAutoHeight = -1;
    bool missingAnchorLogged = false;
    bool overlay = false;
    winrt::weak_ref<FrameworkElement> reservedButton;
    Thickness originalMargin{};
    double reservedWidth = 0;
};
[[clang::no_destroy]] std::map<HWND, std::unique_ptr<PillInstance>> pillInstances;
std::recursive_mutex instancesMutex;
thread_local PillInstance* activeInstance = nullptr;
std::atomic<int> mainPosition{0}, secondaryPosition{-2}, centerOffset{0};
std::atomic<bool> showPrimary{true}, showSecondary{true};
std::atomic<int> cpuPercent{-1}, ramPercent{-1}, gpuPercent{-1};
struct NetworkRates { double upload = -1, download = -1; };
SRWLOCK networkLock = SRWLOCK_INIT;
NetworkRates networkRates;
std::wstring networkAdapterName;
void PublishNetwork(NetworkRates rates, std::wstring const& adapter = L"") {
    AcquireSRWLockExclusive(&networkLock);
    networkRates = rates;
    networkAdapterName = adapter;
    ReleaseSRWLockExclusive(&networkLock);
}
struct NetworkSnapshot { NetworkRates rates; std::wstring adapter; };
NetworkSnapshot ReadNetworkSnapshot() {
    AcquireSRWLockShared(&networkLock);
    NetworkSnapshot snapshot{networkRates, networkAdapterName};
    ReleaseSRWLockShared(&networkLock);
    return snapshot;
}
std::wstring FormatRate(double rate) {
    if (!std::isfinite(rate) || rate < 0) return L"--";
    constexpr wchar_t const* byteUnits[]{L"B/s", L"KB/s", L"MB/s", L"GB/s", L"TB/s"};
    constexpr wchar_t const* bitUnits[]{L"bps", L"Kbps", L"Mbps", L"Gbps", L"Tbps"};
    auto units = networkBits ? bitUnits : byteUnits;
    if (networkBits) rate *= 8.0;
    unsigned unit = 0;
    while (rate >= 999.5 && unit < 4) { rate /= 1000.0; ++unit; }
    wchar_t buffer[64];
    if (!unit || rate >= 100) swprintf_s(buffer, L"%.0f %s", rate, units[unit]);
    else swprintf_s(buffer, L"%.1f %s", rate, units[unit]);
    return buffer;
}

// Resolve the value from the group's owned logical children. XAML retains
// native controls, but an individually projected control's weak reference can
// expire when its temporary projection is released.
TextBlock FindValue(StackPanel const& group, wchar_t const* name) {
    if (!group) return nullptr;
    for (auto const& child : group.Children()) {
        auto border = child.try_as<Border>();
        auto grid = border ? border.Child().try_as<Grid>() : nullptr;
        if (!grid) continue;
        for (auto const& element : grid.Children()) {
            auto info = element.try_as<StackPanel>();
            if (!info) continue;
            for (auto const& row : info.Children()) {
                auto text = row.try_as<TextBlock>();
                if (text && text.Name() == name) return text;
            }
        }
    }
    return nullptr;
}

// Plain data only crosses threads. Use timestamps rather than sample counts so
// delayed sampling/sleep does not compress old history into a fresh graph.
struct GraphSample { ULONGLONG time; std::array<double, 5> values; };
SRWLOCK historyLock = SRWLOCK_INIT;
std::deque<GraphSample> graphHistory;
void RecordGraphSample() {
    auto rates = ReadNetworkSnapshot().rates;
    GraphSample sample{GetTickCount64(), {
        showCpu ? double(cpuPercent.load()) : -1,
        showRam ? double(ramPercent.load()) : -1,
        showGpu ? double(gpuPercent.load()) : -1,
        showNetwork ? rates.upload : -1,
        showNetwork ? rates.download : -1}};
    AcquireSRWLockExclusive(&historyLock);
    graphHistory.push_back(sample);
    while (!graphHistory.empty() && sample.time - graphHistory.front().time > 60000)
        graphHistory.pop_front();
    ReleaseSRWLockExclusive(&historyLock);
}

void DrawGraphs(StackPanel const& group) {
    if (!group) return;
    AcquireSRWLockShared(&historyLock);
    auto history = graphHistory;
    ReleaseSRWLockShared(&historyLock);
    auto appearance = GetAppearance();
    auto now = GetTickCount64();
    double networkMax = 1;
    for (auto const& sample : history) {
        if (now - sample.time > 60000) continue;
        networkMax = std::max(networkMax, std::max(sample.values[3], sample.values[4]));
    }
    // Headroom keeps the busiest network point away from the top edge.
    networkMax *= 1.1;
    for (uint32_t metric = 0; metric < group.Children().Size(); ++metric) {
        auto pill = group.Children().GetAt(metric).as<Border>();
        if (pill.Visibility() != Visibility::Visible) continue;
        auto grid = pill.Child().as<Grid>();
        auto style = StyleFor(metric);
        auto boxed = grid.Children().GetAt(2).as<Canvas>();
        auto background = grid.Children().GetAt(3).as<Canvas>();
        boxed.Children().Clear();
        background.Children().Clear();
        if (style == GraphStyle::None) continue;
        auto canvas = style == GraphStyle::Boxed ? boxed : background;
        double width = style == GraphStyle::Boxed ? appearance.graphWidth : grid.ActualWidth();
        if (width <= 2) continue;
        double height = canvas.Height();
        double inset = std::max(1.0, appearance.stroke / 2);
        double scale = metric < 3 ? 100.0 : networkMax;
        winrt::Windows::UI::Xaml::Shapes::Polyline line{nullptr};
        winrt::Windows::UI::Xaml::Shapes::Polygon area{nullptr};
        ULONGLONG previous = 0;
        float lastX = 0;
        auto finishArea = [&] {
            if (area) area.Points().Append(winrt::Windows::Foundation::Point{lastX, float(height)});
            area = nullptr;
        };
        for (auto const& sample : history) {
            if (now - sample.time > 60000) continue;
            double value = sample.values[metric];
            if (!std::isfinite(value) || value < 0) { finishArea(); line = nullptr; previous = 0; continue; }
            // Break after missing readings and long pauses; never draw a bridge.
            if (!line || (previous && sample.time - previous > 2500)) {
                finishArea();
                if (style == GraphStyle::Background) {
                    area = winrt::Windows::UI::Xaml::Shapes::Polygon();
                    auto fill = appearance.graphColor;
                    fill.A = appearance.fillAlpha;
                    area.Fill(SolidColorBrush(fill));
                    canvas.Children().Append(area);
                }
                line = winrt::Windows::UI::Xaml::Shapes::Polyline();
                auto stroke = appearance.graphColor;
                stroke.A = style == GraphStyle::Background ? appearance.backgroundLineAlpha : 255;
                line.Stroke(SolidColorBrush(stroke));
                line.StrokeThickness(appearance.stroke);
                canvas.Children().Append(line);
            }
            float x = float(inset + (width - 2 * inset) * (1.0 - double(now - sample.time) / 60000.0));
            float y = float(height - inset - (height - 2 * inset) * std::clamp(value / scale, 0.0, 1.0));
            if (area) {
                if (area.Points().Size() == 0)
                    area.Points().Append(winrt::Windows::Foundation::Point{x, float(height)});
                area.Points().Append(winrt::Windows::Foundation::Point{x, y});
            }
            line.Points().Append(winrt::Windows::Foundation::Point{x, y});
            lastX = x;
            previous = sample.time;
        }
        finishArea();
    }
}

void UpdateResourceFlyouts();
void CloseResourceFlyouts(StackPanel const& group);
struct CpuProcessRow { DWORD pid; std::wstring name; double percent; };
struct CpuDetailSnapshot {
    double ghz = -1;
    std::vector<CpuProcessRow> processes;
    bool ready = false;
};
SRWLOCK cpuDetailLock = SRWLOCK_INIT;
CpuDetailSnapshot cpuDetailSnapshot;
std::atomic<ULONGLONG> cpuDetailDemandUntil{0};
CpuDetailSnapshot ReadCpuDetails() {
    AcquireSRWLockShared(&cpuDetailLock);
    auto snapshot = cpuDetailSnapshot;
    ReleaseSRWLockShared(&cpuDetailLock);
    return snapshot;
}
void PublishCpuDetails(CpuDetailSnapshot snapshot) {
    AcquireSRWLockExclusive(&cpuDetailLock);
    cpuDetailSnapshot = std::move(snapshot);
    ReleaseSRWLockExclusive(&cpuDetailLock);
}

struct MemoryProcessRow { DWORD pid; std::wstring name; uint64_t bytes; };
struct MemoryDetailSnapshot {
    uint64_t total = 0, available = 0;
    std::wstring hardware;
    std::vector<MemoryProcessRow> processes;
    bool ready = false;
};
SRWLOCK memoryDetailLock = SRWLOCK_INIT;
MemoryDetailSnapshot memoryDetailSnapshot;
std::atomic<ULONGLONG> memoryDetailDemandUntil{0};
MemoryDetailSnapshot ReadMemoryDetails() {
    AcquireSRWLockShared(&memoryDetailLock);
    auto result = memoryDetailSnapshot;
    ReleaseSRWLockShared(&memoryDetailLock);
    return result;
}
void PublishMemoryDetails(MemoryDetailSnapshot result) {
    AcquireSRWLockExclusive(&memoryDetailLock);
    memoryDetailSnapshot = std::move(result);
    ReleaseSRWLockExclusive(&memoryDetailLock);
}
std::wstring MemoryAmount(uint64_t bytes, bool alwaysGB = false) {
    wchar_t text[48];
    if (alwaysGB || bytes >= (uint64_t(1) << 30)) swprintf_s(text, L"%.1f GB", double(bytes) / 1073741824.0);
    else swprintf_s(text, L"%.1f MB", double(bytes) / 1048576.0);
    return text;
}
// Bounded SMBIOS Type 17 reader. Empty slots and truncated structures are ignored.
struct MemoryHardware { std::wstring type; uint32_t speed = 0; };
MemoryHardware ParseMemoryHardware(BYTE const* data, size_t size) {
    MemoryHardware result;
    bool mixed = false;
    for (size_t offset = 0; offset + 4 <= size;) {
        auto row = data + offset;
        size_t length = row[1];
        if (length < 4 || length > size - offset) break;
        auto word = [&](size_t at) -> uint32_t {
            return at + 2 <= length ? uint32_t(row[at]) | (uint32_t(row[at + 1]) << 8) : 0;
        };
        auto dword = [&](size_t at) -> uint32_t {
            return at + 4 <= length ? uint32_t(row[at]) | (uint32_t(row[at + 1]) << 8) |
                (uint32_t(row[at + 2]) << 16) | (uint32_t(row[at + 3]) << 24) : 0;
        };
        if (row[0] == 17 && length >= 0x15 && word(0x0C) != 0) {
            std::wstring type;
            switch (row[0x12]) {
                case 0x12: type = L"DDR"; break;
                case 0x13: type = L"DDR2"; break;
                case 0x18: type = L"DDR3"; break;
                case 0x1A: type = L"DDR4"; break;
                case 0x1B: type = L"LPDDR"; break;
                case 0x1C: type = L"LPDDR2"; break;
                case 0x1D: type = L"LPDDR3"; break;
                case 0x1E: type = L"LPDDR4"; break;
                case 0x22: type = L"DDR5"; break;
                case 0x23: type = L"LPDDR5"; break;
            }
            if (!type.empty()) {
                if (!result.type.empty() && result.type != type) mixed = true;
                else result.type = type;
            }
            uint32_t speed = word(0x20); // Configured speed; do not claim rated speed as configured.
            if (speed == 0xFFFF) speed = dword(0x58) & 0x7FFFFFFF;
            if (speed && (!result.speed || speed < result.speed)) result.speed = speed;
        }
        if (row[0] == 127) break;
        size_t end = offset + length;
        while (end + 1 < size && (data[end] || data[end + 1])) ++end;
        if (end + 1 >= size) break;
        offset = end + 2;
    }
    if (mixed) result.type = L"Mixed memory";
    return result;
}
struct MemoryDetailsProbe {
    std::wstring hardware;
    bool initialized = false;
    void Init() {
        initialized = true;
        ULONGLONG installedKB = 0;
        GetPhysicallyInstalledSystemMemory(&installedKB);
        if (installedKB) {
            wchar_t text[48];
            double gb = double(installedKB) / 1048576.0;
            if (std::abs(gb - std::round(gb)) < 0.05) swprintf_s(text, L"%.0f GB", gb);
            else swprintf_s(text, L"%.1f GB", gb);
            hardware = text;
        }
        constexpr DWORD provider = 0x52534D42; // 'RSMB'
        UINT size = GetSystemFirmwareTable(provider, 0, nullptr, 0);
        MemoryHardware details;
        if (size >= 8 && size <= 16 * 1024 * 1024) {
            std::vector<BYTE> raw(size);
            UINT received = GetSystemFirmwareTable(provider, 0, raw.data(), size);
            if (received >= 8 && received <= size) {
                uint32_t length = uint32_t(raw[4]) | (uint32_t(raw[5]) << 8) |
                    (uint32_t(raw[6]) << 16) | (uint32_t(raw[7]) << 24);
                if (length <= received - 8) details = ParseMemoryHardware(raw.data() + 8, length);
            }
        }
        if (!details.type.empty()) { if (!hardware.empty()) hardware += L" "; hardware += details.type; }
        if (details.speed) { if (!hardware.empty()) hardware += L" · "; hardware += std::to_wstring(details.speed) + L" MHz"; }
    }
    void Sample(unsigned) {
        if (!initialized) Init();
        MemoryDetailSnapshot result;
        result.hardware = hardware;
        MEMORYSTATUSEX memory{sizeof(memory)};
        if (GlobalMemoryStatusEx(&memory)) { result.total = memory.ullTotalPhys; result.available = memory.ullAvailPhys; }
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (snapshot != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32W entry{}; entry.dwSize = sizeof(entry);
            // Local ABI-compatible EX2 structure: older Windhawk SDK headers may lack its declaration.
            struct Counters {
                PROCESS_MEMORY_COUNTERS_EX base;
                SIZE_T privateWorkingSet;
                ULONG64 sharedCommit;
            };
            static_assert(sizeof(Counters) == 96, "EX2 memory counters require the x64 Windows ABI");
            using ReadCounters = BOOL (WINAPI*)(HANDLE, PPROCESS_MEMORY_COUNTERS, DWORD);
            auto read = reinterpret_cast<ReadCounters>(GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "K32GetProcessMemoryInfo"));
            if (read && Process32FirstW(snapshot, &entry)) do {
                if (!entry.th32ProcessID) continue;
                HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, entry.th32ProcessID);
                if (!process) { continue; }
                Counters counters{}; counters.base.cb = sizeof(counters);
                BOOL ok = read(process, reinterpret_cast<PPROCESS_MEMORY_COUNTERS>(&counters), sizeof(counters));
                CloseHandle(process);
                if (ok) result.processes.push_back({entry.th32ProcessID, entry.szExeFile, uint64_t(counters.privateWorkingSet)});
            } while (Process32NextW(snapshot, &entry));
            result.ready = read != nullptr;
            CloseHandle(snapshot);
        }
        std::sort(result.processes.begin(), result.processes.end(), [](auto const& a, auto const& b) {
            return a.bytes != b.bytes ? a.bytes > b.bytes : a.pid < b.pid;
        });
        if (result.processes.size() > 10) result.processes.resize(10);
        PublishMemoryDetails(std::move(result));
    }
};

struct GpuDetailSnapshot {
    std::wstring name;
    uint64_t dedicatedTotal = 0, sharedTotal = 0;
    double dedicated = -1, shared = -1;
    std::vector<CpuProcessRow> processes;
    bool ready = false;
};
SRWLOCK gpuDetailLock = SRWLOCK_INIT;
GpuDetailSnapshot gpuDetailSnapshot;
std::atomic<ULONGLONG> gpuDetailDemandUntil{0};
GpuDetailSnapshot ReadGpuDetails() {
    AcquireSRWLockShared(&gpuDetailLock);
    auto result = gpuDetailSnapshot;
    ReleaseSRWLockShared(&gpuDetailLock);
    return result;
}
void PublishGpuDetails(GpuDetailSnapshot result) {
    AcquireSRWLockExclusive(&gpuDetailLock);
    gpuDetailSnapshot = std::move(result);
    ReleaseSRWLockExclusive(&gpuDetailLock);
}
std::wstring GpuMemoryAmount(double used, uint64_t total) {
    wchar_t text[64];
    if (used < 0) swprintf_s(text, L"-- / %.1f GB", double(total) / 1073741824.0);
    else swprintf_s(text, L"%.1f / %.1f GB", used / 1073741824.0, double(total) / 1073741824.0);
    return text;
}
// Called on the taskbar thread only; no global strong TextBlock references.
void UpdateMetrics() {
    auto group = activeInstance->group.get();
    auto cpu = FindValue(group, L"ResourcePillsValueCPU");
    auto ram = FindValue(group, L"ResourcePillsValueRAM");
    auto gpu = FindValue(group, L"ResourcePillsValueGPU");
    auto update = [](TextBlock const& text, int value) {
        if (!text) return;
        wchar_t buffer[16];
        if (value < 0) wcscpy_s(buffer, L"--%");
        else swprintf_s(buffer, L"%d%%", value);
        if (text.Text() != buffer) text.Text(buffer);
    };
    update(cpu, cpuPercent.load());
    update(ram, ramPercent.load());
    update(gpu, gpuPercent.load());
    auto rates = ReadNetworkSnapshot().rates;
    auto upload = FindValue(group, L"ResourcePillsValueUpload");
    auto download = FindValue(group, L"ResourcePillsValueDownload");
    if (upload) {
        auto value = FormatRate(rates.upload);
        if (upload.Text() != value) upload.Text(value);
    }
    if (download) {
        auto value = FormatRate(rates.download);
        if (download.Text() != value) download.Text(value);
    }
    DrawGraphs(group);
    UpdateResourceFlyouts();
}

struct CpuSample {
    uint64_t idle = 0, kernel = 0, user = 0;
    bool ready = false;
};
uint64_t Ticks(FILETIME const& value) {
    return (uint64_t(value.dwHighDateTime) << 32) | value.dwLowDateTime;
}
void SampleMetrics(CpuSample& previous) {
    if (showCpu) {
        FILETIME idle{}, kernel{}, user{};
        if (GetSystemTimes(&idle, &kernel, &user)) {
            CpuSample current{Ticks(idle), Ticks(kernel), Ticks(user), true};
            int percent = -1;
            if (previous.ready && current.idle >= previous.idle &&
                current.kernel >= previous.kernel && current.user >= previous.user) {
                auto total = (current.kernel - previous.kernel) + (current.user - previous.user);
                auto idleDelta = current.idle - previous.idle;
                if (total && idleDelta <= total) {
                    // Kernel time already includes idle time; subtract it once.
                    double busy = 100.0 * double(total - idleDelta) / double(total);
                    percent = std::clamp(static_cast<int>(busy + 0.5), 0, 100);
                }
            }
            previous = current;
            cpuPercent.store(percent);
        } else {
            previous.ready = false;
            cpuPercent.store(-1);
        }
    }
    if (showRam) {
        MEMORYSTATUSEX memory{};
        memory.dwLength = sizeof(memory);
        ramPercent.store(GlobalMemoryStatusEx(&memory)
            ? static_cast<int>(std::min<DWORD>(memory.dwMemoryLoad, 100)) : -1);
    }
}

// The worker owns DXGI/PDH state; only the percentage crosses to the UI thread.
double ProcessCpuShare(uint64_t before, uint64_t after, ULONGLONG elapsedMs, DWORD processors) {
    if (after < before || !elapsedMs || !processors) return -1;
    return std::clamp(double(after - before) * 100 / (double(elapsedMs) * 10000 * processors), 0.0, 100.0);
}
struct CpuDetailsProbe {
    struct Previous { uint64_t created, busy; ULONGLONG time; };
    std::map<DWORD, Previous> previous;
    PDH_HQUERY query = nullptr;
    PDH_HCOUNTER performance = nullptr, frequency = nullptr;
    double nominalMHz = 0;
    bool initialized = false;
    ~CpuDetailsProbe() { if (query) PdhCloseQuery(query); }
    void Init() {
        initialized = true;
        HKEY key = nullptr;
        DWORD value = 0, bytes = sizeof(value), type = 0;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS) {
            if (RegQueryValueExW(key, L"~MHz", nullptr, &type, reinterpret_cast<BYTE*>(&value), &bytes) == ERROR_SUCCESS && type == REG_DWORD)
                nominalMHz = value;
            RegCloseKey(key);
        }
        PDH_STATUS status = PdhOpenQueryW(nullptr, 0, &query);
        if (status == ERROR_SUCCESS) {
            auto perfStatus = PdhAddEnglishCounterW(query, L"\\Processor Information(_Total)\\% Processor Performance", 0, &performance);
            auto freqStatus = PdhAddEnglishCounterW(query, L"\\Processor Information(_Total)\\Processor Frequency", 0, &frequency);
            if (perfStatus != ERROR_SUCCESS) performance = nullptr;
            if (freqStatus != ERROR_SUCCESS) frequency = nullptr;
        }
    }
    double ClockGHz() {
        if (!initialized) Init();
        if (!query || PdhCollectQueryData(query) != ERROR_SUCCESS) return -1;
        auto read = [](PDH_HCOUNTER counter) {
            if (!counter) return -1.0;
            PDH_FMT_COUNTERVALUE value{};
            auto status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE | PDH_FMT_NOCAP100, nullptr, &value);
            if (status != ERROR_SUCCESS || (value.CStatus != PDH_CSTATUS_VALID_DATA && value.CStatus != PDH_CSTATUS_NEW_DATA) || !std::isfinite(value.doubleValue)) return -1.0;
            return value.doubleValue;
        };
        double ratio = read(performance);
        if (nominalMHz > 0 && ratio > 0 && ratio < 1000) return nominalMHz * ratio / 100000;
        double mhz = read(frequency);
        return mhz > 0 ? mhz / 1000 : -1;
    }
    void Reset() {
        if (!initialized && previous.empty()) return;
        previous.clear();
        if (query) PdhCloseQuery(query);
        query = nullptr; performance = nullptr; frequency = nullptr;
        initialized = false;
        PublishCpuDetails({});
    }
    void Sample(unsigned) {
        CpuDetailSnapshot snapshot;
        snapshot.ghz = ClockGHz();
        HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (handle == INVALID_HANDLE_VALUE) { previous.clear(); PublishCpuDetails(std::move(snapshot)); return; }
        struct CloseSnapshot { HANDLE value; ~CloseSnapshot(){ CloseHandle(value); } } close{handle};
        PROCESSENTRY32W entry{}; entry.dwSize = sizeof(entry);
        std::map<DWORD, Previous> next;
        DWORD processors = GetActiveProcessorCount(ALL_PROCESSOR_GROUPS);
        if (Process32FirstW(handle, &entry)) do {
            if (!entry.th32ProcessID) continue;
            HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, entry.th32ProcessID);
            if (!process) { continue; }
            FILETIME created{}, exited{}, kernel{}, user{};
            BOOL ok = GetProcessTimes(process, &created, &exited, &kernel, &user);
            CloseHandle(process);
            if (!ok) { continue; }
            uint64_t birth = Ticks(created), busy = Ticks(kernel) + Ticks(user);
            ULONGLONG now = GetTickCount64();
            auto old = previous.find(entry.th32ProcessID);
            if (old != previous.end() && old->second.created == birth) {
                double percent = ProcessCpuShare(old->second.busy, busy, now - old->second.time, processors);
                if (percent >= 0) snapshot.processes.push_back({entry.th32ProcessID, entry.szExeFile, percent});
            }
            next.emplace(entry.th32ProcessID, Previous{birth, busy, now});
        } while (Process32NextW(handle, &entry));
        snapshot.ready = !previous.empty();
        previous = std::move(next);
        std::sort(snapshot.processes.begin(), snapshot.processes.end(), [](auto const& a, auto const& b) {
            if (a.percent != b.percent) return a.percent > b.percent;
            return a.pid < b.pid;
        });
        if (snapshot.processes.size() > 10) snapshot.processes.resize(10);
        PublishCpuDetails(std::move(snapshot));
    }
};

std::vector<CpuProcessRow> RankGpuProcesses(
    std::map<DWORD, std::map<std::wstring, double>> const& engines,
    std::map<DWORD, std::wstring> const& names) {
    std::vector<CpuProcessRow> result;
    for (auto const& [pid, perEngine] : engines) {
        double busiest = 0;
        for (auto const& [key, value] : perEngine) busiest = std::max(busiest, value);
        auto name = names.find(pid);
        if (name != names.end()) result.push_back({pid, name->second, std::clamp(busiest, 0.0, 100.0)});
    }
    std::sort(result.begin(), result.end(), [](auto const& a, auto const& b) {
        return a.percent != b.percent ? a.percent > b.percent : a.pid < b.pid;
    });
    if (result.size() > 10) result.resize(10);
    return result;
}

struct GpuProbe {
    struct Adapter {
        std::wstring name;
        unsigned high, low;
        bool software;
        uint64_t dedicated = 0, shared = 0;
    };
    std::vector<Adapter> adapters;
    PDH_HQUERY query = nullptr;
    PDH_HCOUNTER engineCounter = nullptr, dedicatedCounter = nullptr, sharedCounter = nullptr;
    bool primed = false;
    int selectedAdapter = -1;
    ~GpuProbe() { if (query) PdhCloseQuery(query); }

    void Init() {
        winrt::com_ptr<IDXGIFactory1> factory;
        HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), factory.put_void());
        if (FAILED(hr)) {
            Wh_Log(L"RP: GPU inventory failed HRESULT=0x%08X", (unsigned)hr);
        } else {
            for (UINT i = 0; ; ++i) {
                winrt::com_ptr<IDXGIAdapter1> adapter;
                hr = factory->EnumAdapters1(i, adapter.put());
                if (hr == DXGI_ERROR_NOT_FOUND) break;
                if (FAILED(hr)) {
                    Wh_Log(L"RP: GPU enumeration failed index=%u HRESULT=0x%08X", i, (unsigned)hr);
                    break;
                }
                DXGI_ADAPTER_DESC1 desc{};
                if (FAILED(adapter->GetDesc1(&desc))) continue;
                bool software = (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) != 0;
                adapters.push_back({desc.Description, (unsigned)desc.AdapterLuid.HighPart,
                                    (unsigned)desc.AdapterLuid.LowPart, software, uint64_t(desc.DedicatedVideoMemory), uint64_t(desc.SharedSystemMemory)});
            }
        }
        unsigned hardwareCount = 0;
        for (size_t i = 0; i < adapters.size(); ++i) {
            if (!adapters[i].software) { ++hardwareCount; selectedAdapter = static_cast<int>(i); }
        }
        if (hardwareCount != 1) {
            selectedAdapter = -1;
            Wh_Log(L"RP: GPU selection unavailable: hardware adapters=%u; displaying --%%", hardwareCount);
            return;
        }
        PDH_STATUS status = PdhOpenQueryW(nullptr, 0, &query);
        if (status == ERROR_SUCCESS)
            status = PdhAddEnglishCounterW(query,
                L"\\GPU Engine(*)\\Utilization Percentage", 0, &engineCounter);
        if (status == ERROR_SUCCESS) {
            auto dedicatedStatus = PdhAddEnglishCounterW(query, L"\\GPU Adapter Memory(*)\\Dedicated Usage", 0, &dedicatedCounter);
            auto sharedStatus = PdhAddEnglishCounterW(query, L"\\GPU Adapter Memory(*)\\Shared Usage", 0, &sharedCounter);
            if (dedicatedStatus != ERROR_SUCCESS) dedicatedCounter = nullptr;
            if (sharedStatus != ERROR_SUCCESS) sharedCounter = nullptr;
        }
        if (status != ERROR_SUCCESS) Wh_Log(L"RP: GPU engine query setup failed status=0x%08X adapters=%u",
            (unsigned)status, (unsigned)adapters.size());
        if (status != ERROR_SUCCESS) {
            if (query) PdhCloseQuery(query);
            query = nullptr;
            engineCounter = nullptr;
        }
    }

    GpuDetailSnapshot EmptyDetails() const {
        GpuDetailSnapshot result;
        if (selectedAdapter >= 0) {
            auto const& adapter = adapters[selectedAdapter];
            result.name = adapter.name;
            result.dedicatedTotal = adapter.dedicated;
            result.sharedTotal = adapter.shared;
        }
        return result;
    }
    double MemoryUsage(PDH_HCOUNTER counter) {
        if (!counter || selectedAdapter < 0) return -1;
        DWORD bytes = 0, count = 0;
        auto status = PdhGetFormattedCounterArrayW(counter, PDH_FMT_DOUBLE, &bytes, &count, nullptr);
        if (status != PDH_MORE_DATA || !bytes) return -1;
        std::unique_ptr<BYTE[]> data;
        for (int attempt = 0; attempt < 3; ++attempt) {
            data = std::make_unique<BYTE[]>(bytes);
            status = PdhGetFormattedCounterArrayW(counter, PDH_FMT_DOUBLE, &bytes, &count,
                reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(data.get()));
            if (status != PDH_MORE_DATA) break;
        }
        if (status != ERROR_SUCCESS) return -1;
        double total = 0;
        bool found = false;
        auto values = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(data.get());
        auto const& selected = adapters[selectedAdapter];
        for (DWORD i = 0; i < count; ++i) {
            auto const& value = values[i];
            if ((value.FmtValue.CStatus != PDH_CSTATUS_VALID_DATA && value.FmtValue.CStatus != PDH_CSTATUS_NEW_DATA) ||
                !std::isfinite(value.FmtValue.doubleValue) || value.FmtValue.doubleValue < 0) continue;
            std::wstring name = value.szName ? value.szName : L"";
            auto pos = name.find(L"luid_");
            unsigned high = 0, low = 0;
            if (pos == std::wstring::npos || swscanf(name.c_str() + pos, L"luid_0x%x_0x%x", &high, &low) != 2) continue;
            if (high == selected.high && low == selected.low) { found = true; total += value.FmtValue.doubleValue; }
        }
        return found ? total : -1;
    }
    void Sample(unsigned tick) {
        gpuPercent.store(-1);
        PublishGpuDetails(EmptyDetails());
        if (!query || !engineCounter) return;
        bool log = tick <= 6 || tick % 30 == 0;
        PDH_STATUS status = PdhCollectQueryData(query);
        if (status != ERROR_SUCCESS) {
            primed = false;
            return;
        }
        if (!primed) {
            primed = true;
            return;
        }
        DWORD bytes = 0, count = 0;
        status = PdhGetFormattedCounterArrayW(engineCounter, PDH_FMT_DOUBLE | PDH_FMT_NOCAP100,
                                               &bytes, &count, nullptr);
        if (status != PDH_MORE_DATA || !bytes) {
            return;
        }
        std::unique_ptr<BYTE[]> storage;
        // The instance set may grow between sizing and reading.
        for (int attempt = 0; attempt < 3; ++attempt) {
            storage = std::make_unique<BYTE[]>(bytes);
            status = PdhGetFormattedCounterArrayW(engineCounter, PDH_FMT_DOUBLE | PDH_FMT_NOCAP100,
                &bytes, &count, reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(storage.get()));
            if (status != PDH_MORE_DATA) break;
        }
        if (status != ERROR_SUCCESS) {
            return;
        }
        struct Engine { unsigned high, low, physical, number; std::wstring type; double usage = 0; };
        std::map<std::wstring, Engine> engines;
        auto values = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(storage.get());
        unsigned unmatched = 0;
        bool detailsWanted = GetTickCount64() < gpuDetailDemandUntil.load();
        std::map<DWORD, std::map<std::wstring, double>> processEngines;
        for (DWORD i = 0; i < count; ++i) {
            auto const& value = values[i];
            if ((value.FmtValue.CStatus != PDH_CSTATUS_VALID_DATA &&
                 value.FmtValue.CStatus != PDH_CSTATUS_NEW_DATA) ||
                !std::isfinite(value.FmtValue.doubleValue)) continue;
            std::wstring name = value.szName ? value.szName : L"";
            auto pos = name.find(L"luid_");
            unsigned high = 0, low = 0, physical = 0, number = 0;
            wchar_t type[128]{};
            if (pos == std::wstring::npos ||
                swscanf(name.c_str() + pos, L"luid_0x%x_0x%x_phys_%u_eng_%u_engtype_%127ls",
                    &high, &low, &physical, &number, type) != 5) {
                ++unmatched;
                if (log && unmatched <= 3) Wh_Log(L"RP: GPU unparsed instance=[%s]", name.c_str());
                continue;
            }
            wchar_t key[96];
            swprintf_s(key, L"%08X_%08X_%u_%u", high, low, physical, number);
            auto [it, added] = engines.try_emplace(key, Engine{high, low, physical, number, type, 0});
            // Sum processes using the SAME engine, never unrelated engines.
            it->second.usage += std::max(0.0, value.FmtValue.doubleValue);
            if (detailsWanted && selectedAdapter >= 0 && high == adapters[selectedAdapter].high && low == adapters[selectedAdapter].low) {
                unsigned pid = 0;
                if (swscanf(name.c_str(), L"pid_%u_", &pid) == 1 && pid)
                    processEngines[pid][key] += std::max(0.0, value.FmtValue.doubleValue);
            }

        }
        // Publish utilization on every valid sample.
        if (selectedAdapter >= 0) {
            auto const& selected = adapters[selectedAdapter];
            bool found = false;
            double busiest = 0;
            for (auto const& [key, engine] : engines) {
                if (engine.high == selected.high && engine.low == selected.low) {
                    found = true;
                    busiest = std::max(busiest, engine.usage);
                }
            }
            if (found) gpuPercent.store(static_cast<int>(std::clamp(busiest, 0.0, 100.0) + 0.5));
        }
        if (detailsWanted) {
            auto details = EmptyDetails();
            details.dedicated = MemoryUsage(dedicatedCounter);
            details.shared = MemoryUsage(sharedCounter);
            std::map<DWORD, std::wstring> names;
            HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
            if (snapshot != INVALID_HANDLE_VALUE) {
                PROCESSENTRY32W entry{}; entry.dwSize = sizeof(entry);
                if (Process32FirstW(snapshot, &entry)) do {
                    names.emplace(entry.th32ProcessID, entry.szExeFile);
                } while (Process32NextW(snapshot, &entry));
                CloseHandle(snapshot);
            }
            details.processes = RankGpuProcesses(processEngines, names);
            details.ready = true;
            PublishGpuDetails(std::move(details));
        }

    }
};

struct NetworkProbe {
    struct Previous {
        uint64_t inOctets, outOctets, time;
        int status;
        std::wstring alias;
        bool candidate;
    };
    struct Candidate { uint64_t luid; std::wstring alias; NetworkRates rates; };
    std::map<uint64_t, Previous> previous;
    uint64_t selected = 0;

    static bool Excluded(MIB_IF_ROW2 const& row) {
        std::wstring name = std::wstring(row.Alias) + L" " + row.Description;
        std::transform(name.begin(), name.end(), name.begin(),
            [](wchar_t c) { return static_cast<wchar_t>(towlower(c)); });
        for (auto token : {L"loopback", L"npcap", L"winpcap", L"packet capture"})
            if (name.find(token) != std::wstring::npos) return true;
        return false;
    }

    void Sample(unsigned tick) {
        bool log = tick <= 6 || tick % 30 == 0;
        MIB_IF_TABLE2* table = nullptr;
        DWORD error = GetIfTable2(&table);
        if (error != NO_ERROR || !table) {
            if (log) Wh_Log(L"RP: NET enumeration failed error=%lu", error);
            previous.clear();
            PublishNetwork({});
            return;
        }
        struct ReleaseTable {
            MIB_IF_TABLE2* value;
            ~ReleaseTable() { FreeMibTable(value); }
        } release{table};
        uint64_t now = GetTickCount64();
        std::map<uint64_t, Previous> next;
        std::vector<Candidate> candidates;
        for (ULONG i = 0; i < table->NumEntries; ++i) {
            auto const& row = table->Table[i];
            auto const& flags = row.InterfaceAndOperStatusFlags;
            bool up = row.OperStatus == IfOperStatusUp;
            bool supported = row.Type == IF_TYPE_ETHERNET_CSMACD || row.Type == IF_TYPE_IEEE80211;
            bool excluded = Excluded(row);
            bool candidate = up && flags.HardwareInterface && supported &&
                !flags.FilterInterface && !flags.NotMediaConnected && !flags.Paused && !excluded;
            uint64_t key = row.InterfaceLuid.Value;
            auto old = previous.find(key);
            NetworkRates rates;
            if (up && old != previous.end() && old->second.status == IfOperStatusUp &&
                now > old->second.time && row.InOctets >= old->second.inOctets &&
                row.OutOctets >= old->second.outOctets) {
                double seconds = double(now - old->second.time) / 1000.0;
                rates.download = double(row.InOctets - old->second.inOctets) / seconds;
                rates.upload = double(row.OutOctets - old->second.outOctets) / seconds;
            }
            if (candidate) candidates.push_back({key, row.Alias, rates});
            next.emplace(key, Previous{row.InOctets, row.OutOctets, now,
                                      int(row.OperStatus), row.Alias, candidate});
        }
        previous.swap(next);
        Candidate const* choice = nullptr;
        for (auto const& candidate : candidates)
            if (selected && candidate.luid == selected) choice = &candidate;
        if (!choice) {
            selected = 0;
            // A sole candidate can be retained while warming. For multiple
            // candidates wait for valid rates instead of guessing table order.
            if (candidates.size() == 1) choice = &candidates.front();
            else for (auto const& candidate : candidates) {
                if (candidate.rates.upload < 0 || candidate.rates.download < 0) continue;
                double activity = candidate.rates.upload + candidate.rates.download;
                double best = choice ? choice->rates.upload + choice->rates.download : -1;
                if (!choice || activity > best || (activity == best && candidate.luid < choice->luid))
                    choice = &candidate;
            }
            if (choice) selected = choice->luid;
        }
        PublishNetwork(choice ? choice->rates : NetworkRates{}, choice ? choice->alias : L"");

    }
};

constexpr wchar_t kMarker[] = L"ResourcePillsLayoutSlot";
using HostGetter = void*(WINAPI*)(void*, void*);
using FrameHeight = int(WINAPI*)(void*);
using Decref = void(WINAPI*)(void*);
using StartTaskbar = void(WINAPI*)(void*);
HostGetter getHost = nullptr, secondaryGetHost = nullptr;
FrameHeight frameHeight = nullptr;
Decref decref = nullptr;
StartTaskbar startTaskbarOriginal = nullptr;
void* siteVtable = nullptr;
void* secondarySiteVtable = nullptr;

HWND TaskbarWindow() {
    HWND hwnd = FindWindowW(L"Shell_TrayWnd", nullptr);
    DWORD pid = 0;
    if (hwnd) GetWindowThreadProcessId(hwnd, &pid);
    return pid == GetCurrentProcessId() ? hwnd : nullptr;
}

FrameworkElement TaskbarRoot(HWND hwnd) {
    bool primary = hwnd == TaskbarWindow();
    if (!primary && (!secondarySiteVtable || !secondaryGetHost)) return nullptr;
    HWND taskband = primary ? (HWND)GetPropW(hwnd, L"TaskbandHWND") : FindWindowExW(hwnd, nullptr, L"WorkerW", nullptr);
    if (!taskband) return nullptr;
    auto site = (void**)GetWindowLongPtrW(taskband, 0);
    if (!site) return nullptr;
    int index = 0;
    for (; index < 20 && *site != (primary ? siteVtable : secondarySiteVtable); ++index) ++site;
    if (index == 20) return nullptr;
    auto code = reinterpret_cast<BYTE const*>(frameHeight);
    size_t offset = 0x10;
    if (code[0] == 0x48 && code[1] == 0x83 && code[2] == 0xEC &&
        code[4] == 0x48 && code[5] == 0x83 && code[6] == 0xC1 && code[7] <= 0x7F)
        offset = code[7];
    void* host[2]{};
    (primary ? getHost : secondaryGetHost)(site, host);
    if (!host[1]) return nullptr;
    struct ReleaseHost {
        void* control;
        ~ReleaseHost() { decref(control); }
    } release{host[1]};
    if (!host[0]) return nullptr;
    auto unknown = *(IUnknown**)((BYTE*)host[0] + offset);
    if (!unknown) return nullptr;
    FrameworkElement element{nullptr};
    unknown->QueryInterface(winrt::guid_of<FrameworkElement>(), winrt::put_abi(element));
    auto root = element ? element.XamlRoot() : nullptr;
    return root ? root.Content().try_as<FrameworkElement>() : nullptr;
}

Panel FindTray(DependencyObject const& root, int depth = 0) {
    if (!root || depth > 24) return nullptr;
    if (auto element = root.try_as<FrameworkElement>()) {
        if (element.Name() == L"SystemTrayFrameGrid") {
            auto panel = element.try_as<Panel>();
            if (panel && slot::Classify(panel) != slot::Kind::Unsupported) return panel;
        }
    }
    for (int i = 0; i < VisualTreeHelper::GetChildrenCount(root); ++i)
        if (auto panel = FindTray(VisualTreeHelper::GetChild(root, i), depth + 1)) return panel;
    return nullptr;
}

FrameworkElement FindTrayAnchor(DependencyObject const& root, bool clock, int depth = 0) {
    if (!root || depth > 24) return nullptr;
    if (auto element = root.try_as<FrameworkElement>()) {
        auto name = std::wstring(element.Name());
        auto type = std::wstring(winrt::get_class_name(element));
        if (clock ? (name == L"ClockButton" || name == L"ClockStack" || type.find(L"DateTimeIconContent") != std::wstring::npos) :
                    (name == L"ShowDesktopStack" || name == L"ShowDesktopButton")) return element;
    }
    for (int i = 0; i < VisualTreeHelper::GetChildrenCount(root); ++i)
        if (auto found = FindTrayAnchor(VisualTreeHelper::GetChild(root, i), clock, depth + 1)) return found;
    return nullptr;
}
Panel PositionParent(FrameworkElement const& root, int position, int& index) {
    auto tray = FindTray(root);
    if (!tray) return nullptr;
    if (position >= 3) {
        // Use the root grid without adding columns to the application repeater.
        auto grid = root.try_as<Grid>();
        RECT bounds{};
        if (!grid || !GetWindowRect(activeInstance->hwnd, &bounds)) return nullptr;
        double dpi = GetDpiForWindow(activeInstance->hwnd);
        double expected = (bounds.right - bounds.left) * 96.0 / (dpi ? dpi : 96);
        if (grid.ActualWidth() < expected * 0.75) return nullptr;
        index = 0;
        return grid;
    }
    if (position == 0) { index = 0; return tray; }
    auto child = FindTrayAnchor(tray, true);
    if (!child) return nullptr;
    // Anchor the whole clock subtree, never one of the internal
    // text grids inside its button. All three positions share the tray lease.
    while (child) {
        auto owner = VisualTreeHelper::GetParent(child);
        if (owner == tray) {
            if (auto grid = tray.try_as<Grid>()) {
                index = Grid::GetColumn(child);
                if (position == 2) index += Grid::GetColumnSpan(child);
            } else {
                uint32_t at;
                if (!tray.Children().IndexOf(child, at)) return nullptr;
                index = int(at) + (position == 2 ? 1 : 0);
            }
            return tray;
        }
        child = owner ? owner.try_as<FrameworkElement>() : nullptr;
    }
    return nullptr;
}
int EffectivePosition(HWND hwnd) {
    bool primary = hwnd == TaskbarWindow();
    if (primary ? !showPrimary.load() : !showSecondary.load()) return -2;
    int secondary = secondaryPosition.load();
    return hwnd == TaskbarWindow() || secondary == -1 ? mainPosition.load() : secondary;
}

void ReleaseButtonReservation() {
    if (auto button = activeInstance->reservedButton.get()) {
        auto margin = button.Margin();
        // Remove our contribution while retaining independent margin changes.
        margin.Left -= activeInstance->reservedWidth;
        if (margin.Left >= activeInstance->originalMargin.Left - 0.5) button.Margin(margin);
    }
    activeInstance->reservedButton = {};
    activeInstance->reservedWidth = 0;
}
struct ButtonBounds {
    FrameworkElement firstApp{nullptr}, firstAny{nullptr};
    double appLeft = 1e9, anyLeft = 1e9, appRight = 0, launchRight = 0;
    unsigned count = 0;
};
void MeasureButtons(FrameworkElement const& node, Grid const& root, ButtonBounds& bounds, int depth = 0) {
    if (!node || depth > 24 || node.Visibility() != Visibility::Visible || node.Name() == L"ResourcePills") return;
    auto name = std::wstring(node.Name());
    auto type = std::wstring(winrt::get_class_name(node));
    bool app = name.find(L"TaskbarButton") != std::wstring::npos || name.find(L"TaskListButton") != std::wstring::npos;
    bool launch = name.find(L"LaunchListButton") != std::wstring::npos || type.find(L"LaunchListButton") != std::wstring::npos;
    if ((app || launch) && node.ActualWidth() > 8 && node.ActualWidth() < 200) {
        auto p = node.TransformToVisual(root).TransformPoint({0, 0});
        double x = p.X, right = x + node.ActualWidth();
        if (std::isfinite(x) && x >= 0 && right <= root.ActualWidth() + 1) {
            ++bounds.count;
            if (x < bounds.anyLeft) { bounds.anyLeft = x; bounds.firstAny = node; }
            if (app) {
                bounds.appRight = std::max(bounds.appRight, right);
                if (x < bounds.appLeft) { bounds.appLeft = x; bounds.firstApp = node; }
            }
            if (launch) bounds.launchRight = std::max(bounds.launchRight, right);
            return;
        }
    }
    for (int i = 0; i < VisualTreeHelper::GetChildrenCount(node); ++i)
        if (auto child = VisualTreeHelper::GetChild(node, i).try_as<FrameworkElement>())
            MeasureButtons(child, root, bounds, depth + 1);
}
// Pure placement rule: dynamic center can move right for buttons, but never
// overlaps the tray or shifts left of its requested center to force a fit.
bool ResolveOverlayLeft(int position, double rootWidth, double width, double firstLeft,
                        double buttonsRight, double trayLeft, double offset, double& left) {
    if (position == 3 || position == 6) left = firstLeft - width - 5;
    else if (position == 4) left = buttonsRight + 5;
    else left = std::max((rootWidth - width) / 2 + offset, buttonsRight + 5);
    return std::isfinite(left) && left >= 5 && left + width + 5 <= trayLeft;
}
struct TaskbarFit { double height = 48, offsetY = 0; bool detected = false; };
TaskbarFit ResolveTaskbarFit() {
    TaskbarFit fit;
    RECT rect{};
    if (GetWindowRect(activeInstance->hwnd, &rect)) {
        UINT dpi = GetDpiForWindow(activeInstance->hwnd);
        double height = (rect.bottom - rect.top) * 96.0 / (dpi ? dpi : 96);
        if (height >= 8) fit.height = height;
    }
    auto parent = activeInstance->parent.get();
    auto root = TaskbarRoot(activeInstance->hwnd);
    // Same styled-background preference as Mawaqit's ResolveAttachedFit.
    // Do not size from a tray panel whose height may itself depend on our pill.
    struct Node { DependencyObject object; int depth; };
    std::vector<Node> pending;
    if (root) pending.push_back({root, 0});
    int visited = 0;
    while (!pending.empty() && visited++ < 350) {
        auto node = pending.back(); pending.pop_back();
        auto element = node.object.try_as<FrameworkElement>();
        if (element && element.Name() == L"BackgroundControl" &&
            winrt::get_class_name(node.object) == L"Taskbar.TaskbarBackground") {
            double height = element.ActualHeight();
            if (height > 15 && height <= fit.height) {
                double offset = 0;
                if (parent && parent.ActualHeight() > 0) {
                    auto origin = element.TransformToVisual(parent).TransformPoint({0, 0});
                    offset = origin.Y + (height - parent.ActualHeight()) / 2;
                }
                if (std::isfinite(offset) && std::abs(offset) <= fit.height)
                    fit = {height, offset, true};
            }
            break;
        }
        if (node.depth >= 12) continue;
        for (int i = VisualTreeHelper::GetChildrenCount(node.object) - 1; i >= 0; --i)
            pending.push_back({VisualTreeHelper::GetChild(node.object, i), node.depth + 1});
    }
    return fit;
}
void UpdateTaskbarFit() {
    auto host = activeInstance->host.get();
    if (!host) return;
    auto a = GetAppearance();
    auto fit = ResolveTaskbarFit();
    bool automatic = a.height == 0;
    double maximum = automatic ? fit.height : std::numeric_limits<double>::infinity();
    if (host.MaxHeight() != maximum) host.MaxHeight(maximum);
    auto translation = host.RenderTransform().try_as<TranslateTransform>();
    if (!translation) { translation = TranslateTransform(); host.RenderTransform(translation); }
    double offset = automatic ? fit.offsetY : 0;
    if (std::abs(translation.Y() - offset) > 0.1) translation.Y(offset);
}

void UpdateOverlayPosition() {
    if (!activeInstance->overlay) return;
    auto surface = activeInstance->surface.get();
    auto host = activeInstance->host.get();
    auto parent = activeInstance->parent.get();
    auto grid = parent ? parent.try_as<Grid>() : nullptr;
    if (!surface || !host || !grid) return;
    auto hide = [&] { if (host.Visibility() != Visibility::Collapsed) host.Visibility(Visibility::Collapsed); };
    auto tray = FindTray(grid);
    if (!tray) { hide(); return; }
    auto a = GetAppearance();
    // Include configured outer margins in the occupied rectangle. A collapsed
    // overlay still measures its child so it can reappear when space returns.
    auto group = activeInstance->group.get();
    if (!group) return;
    group.Measure({10000, 10000});
    // Measure the Viewbox at the current height limit; reserve its scaled width.
    // Measuring the child explicitly also works while the host is collapsed.
    surface.Measure({10000, 10000});
    double unscaledHeight = surface.DesiredSize().Height;
    double scale = unscaledHeight > 0 ? std::min(1.0, host.MaxHeight() / unscaledHeight) : 1.0;
    double width = surface.DesiredSize().Width * scale;
    if (!std::isfinite(width) || width <= 0) { hide(); return; }
    double trayLeft = tray.TransformToVisual(grid).TransformPoint({0, 0}).X;
    if (width + 10 > trayLeft) { ReleaseButtonReservation(); hide(); return; }
    ButtonBounds buttons;
    MeasureButtons(grid, grid, buttons);
    if (!buttons.count) { ReleaseButtonReservation(); hide(); return; }
    int position = activeInstance->position;
    auto first = position == 6 ? buttons.firstAny : buttons.firstApp;
    if (position == 3 || position == 6) {
        if (first) {
            auto old = activeInstance->reservedButton.get();
            if (old != first) ReleaseButtonReservation();
            if (!activeInstance->reservedButton.get()) {
                activeInstance->originalMargin = first.Margin();
                activeInstance->reservedButton = winrt::make_weak(first);
            }
            double wanted = width + 10;
            if (std::abs(activeInstance->reservedWidth - wanted) > 0.5) {
                auto margin = first.Margin();
                margin.Left += wanted - activeInstance->reservedWidth;
                first.Margin(margin);
                activeInstance->reservedWidth = wanted;
                grid.UpdateLayout();
                buttons = {};
                MeasureButtons(grid, grid, buttons);
                first = position == 6 ? buttons.firstAny : buttons.firstApp;
                if (first != activeInstance->reservedButton.get()) { ReleaseButtonReservation(); hide(); return; }
                trayLeft = tray.TransformToVisual(grid).TransformPoint({0, 0}).X;
            }
        } else ReleaseButtonReservation();
    } else ReleaseButtonReservation();
    double firstLeft = position == 6 ? buttons.anyLeft : buttons.appLeft;
    double buttonsRight = std::max(buttons.appRight, buttons.launchRight);
    // Before-icons with no application buttons uses the launch group's trailing edge.
    int placement = position == 3 && !first ? 4 : position;
    double left = 0;
    bool room = ResolveOverlayLeft(placement, grid.ActualWidth(), width, firstLeft,
                                   buttonsRight, trayLeft, centerOffset.load(), left);
    if (position == 3 && first) room = room && left >= buttons.launchRight + 5;
    if (!room) { hide(); return; }
    Thickness margin{left, 0, 0, 0};
    if (std::abs(host.Margin().Left - left) > 0.1) host.Margin(margin);
    if (host.Visibility() != Visibility::Visible) host.Visibility(Visibility::Visible);
}

// Weak C++/WinRT projections may expire while their native XAML controls
// remain attached. The taskbar tree, not weak projection lifetime, owns identity.
struct AttachedPills {
    Panel parent{nullptr};
    Viewbox host{nullptr};
    Border surface{nullptr};
    StackPanel group{nullptr};
    explicit operator bool() const { return !!host; }
};
AttachedPills FindAttachedPills(DependencyObject const& node, int depth = 0) {
    if (!node || depth > 40) return {};
    if (auto panel = node.try_as<Panel>()) {
        for (auto const& child : panel.Children()) {
            auto host = child.try_as<Viewbox>();
            if (!host) continue;
            auto surface = host.Child().try_as<Border>();
            auto group = surface ? surface.Child().try_as<StackPanel>() : nullptr;
            // Recognise dev.32 hosts as well, which did not have a host name.
            if (group && group.Name() == L"ResourcePills") return {panel, host, surface, group};
        }
    }
    for (int i = 0; i < VisualTreeHelper::GetChildrenCount(node); ++i)
        if (auto found = FindAttachedPills(VisualTreeHelper::GetChild(node, i), depth + 1)) return found;
    return {};
}
void RememberAttachedPills(AttachedPills const& found) {
    activeInstance->parent = winrt::make_weak(found.parent);
    activeInstance->host = winrt::make_weak(found.host);
    activeInstance->surface = winrt::make_weak(found.surface);
    activeInstance->group = winrt::make_weak(found.group);
}

void StopNativeHover(HWND hwnd, bool detach);
void RemovePills() {
    StopNativeHover(activeInstance->hwnd, true);
    activeInstance->hover = {};
    ReleaseButtonReservation();
    if (auto group = activeInstance->group.get()) CloseResourceFlyouts(group);
    auto root = TaskbarRoot(activeInstance->hwnd);
    // Keep projected objects alive locally for this UI operation. Remove all
    // recognised hosts, including orphans left by an expired weak projection.
    auto parent = activeInstance->parent.get();
    unsigned removed = 0;
    while (auto found = FindAttachedPills(root)) {
        if (!parent) parent = found.parent;
        uint32_t index;
        if (!found.parent.Children().IndexOf(found.host, index)) break;
        CloseResourceFlyouts(found.group);
        found.parent.Children().RemoveAt(index);
        ++removed;
    }
    // A detached tree may no longer be reachable from the live root.
    if (parent) {
        if (auto host = activeInstance->host.get()) {
            uint32_t index;
            if (parent.Children().IndexOf(host, index)) parent.Children().RemoveAt(index);
        }
        slot::Release(parent, activeInstance->lease);
    }
    if (removed > 1) Wh_Log(L"RP: cleaned %u duplicate hosts hwnd=%p", removed, activeInstance->hwnd);
    activeInstance->parent = {};
    activeInstance->group = {};
    activeInstance->surface = {};
    activeInstance->host = {};
    activeInstance->lease = {};
    activeInstance->overlay = false;
}

// Glyph mapping follows PowerToys Performance Monitor Icons.cs:
// https://github.com/microsoft/PowerToys/blob/main/src/modules/cmdpal/ext/Microsoft.CmdPal.Ext.PerformanceMonitor/Icons.cs
// Font fallback follows PowerToys FontIconGlyphClassifier.cs.
FrameworkElement MakeIcon(wchar_t const* glyph) {
    FontIcon icon;
    icon.Glyph(glyph);
    icon.FontFamily(FontFamily(L"Segoe Fluent Icons, Segoe MDL2 Assets"));
    icon.FontSize(16);
    icon.Width(16);
    icon.Height(16);
    icon.Foreground(SolidColorBrush(winrt::Windows::UI::Color{255, 240, 238, 246}));
    icon.HorizontalAlignment(HorizontalAlignment::Center);
    icon.VerticalAlignment(VerticalAlignment::Center);
    return icon;
}

// CPU flyout prototype: all UI is native Windows.UI.Xaml. No retained strong
// apartment objects; the pill's AttachedFlyout owns the content, resolved locally.
namespace primitives = winrt::Windows::UI::Xaml::Controls::Primitives;
namespace input = winrt::Windows::UI::Xaml::Input;
FrameworkElement FindFlyoutPart(DependencyObject const& node, wchar_t const* name) {
    if (!node) return nullptr;
    if (auto element = node.try_as<FrameworkElement>())
        if (element.Name() == name) return element;
    if (auto panel = node.try_as<Panel>()) {
        for (auto const& child : panel.Children())
            if (auto found = FindFlyoutPart(child, name)) return found;
    } else if (auto border = node.try_as<Border>()) {
        return FindFlyoutPart(border.Child(), name);
    } else if (auto scroll = node.try_as<ScrollViewer>()) {
        return FindFlyoutPart(scroll.Content().try_as<DependencyObject>(), name);
    }
    return nullptr;
}
TextBlock FlyoutText(wchar_t const* text, double size = 12) {
    TextBlock block;
    block.Text(text);
    block.FontSize(size);
    block.Foreground(SolidColorBrush(GetAppearance().identifierColor));
    block.TextWrapping(TextWrapping::NoWrap);
    return block;
}
void OpenResourceTaskManager() {
    wchar_t directory[MAX_PATH]{};
    UINT length = GetSystemDirectoryW(directory, ARRAYSIZE(directory));
    if (!length || length >= ARRAYSIZE(directory)) return;
    std::wstring path = std::wstring(directory) + L"\\Taskmgr.exe";
    STARTUPINFOW startup{sizeof(startup)};
    PROCESS_INFORMATION process{};
    if (CreateProcessW(path.c_str(), nullptr, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startup, &process)) {
        CloseHandle(process.hThread);
        CloseHandle(process.hProcess);
    } else Wh_Log(L"RP: Task Manager launch failed error=%lu", GetLastError());
}
std::wstring ResourceCpuName() {
    wchar_t buffer[256]{};
    DWORD bytes = sizeof(buffer), type = 0;
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS) {
        LONG status = RegQueryValueExW(key, L"ProcessorNameString", nullptr, &type, reinterpret_cast<BYTE*>(buffer), &bytes);
        RegCloseKey(key);
        buffer[ARRAYSIZE(buffer) - 1] = 0;
        if (status == ERROR_SUCCESS && type == REG_SZ) return buffer;
    }
    return L"CPU";
}
void RefreshFlyoutForeground(DependencyObject const& node, winrt::Windows::UI::Color color) {
    if (!node) return;
    if (auto text = node.try_as<TextBlock>()) text.Foreground(SolidColorBrush(color));
    if (auto icon = node.try_as<FontIcon>()) icon.Foreground(SolidColorBrush(color));
    if (auto panel = node.try_as<Panel>()) {
        for (auto const& child : panel.Children()) RefreshFlyoutForeground(child, color);
    } else if (auto scroll = node.try_as<ScrollViewer>()) {
        RefreshFlyoutForeground(scroll.Content().try_as<DependencyObject>(), color);
    }
}
double ResourceFlyoutRadius(Flyout const& flyout, AppearanceConfig const& a) {
    auto content = flyout.Content().try_as<Grid>();
    auto group = flyout.OverlayInputPassThroughElement().try_as<StackPanel>();
    if (content && group && content.Resources().HasKey(winrt::box_value(L"ResourceIndex"))) {
        int resource = winrt::unbox_value<int>(content.Resources().Lookup(winrt::box_value(L"ResourceIndex")));
        if (resource >= 0 && unsigned(resource) < group.Children().Size())
            return group.Children().GetAt(resource).as<Border>().CornerRadius().TopLeft;
    }
    if (auto anchor = flyout.Target().try_as<Border>()) return anchor.CornerRadius().TopLeft;
    auto root = flyout.Content().try_as<Grid>();
    if (root && root.Resources().HasKey(winrt::box_value(L"ResourcePillRadius")))
        return winrt::unbox_value<double>(root.Resources().Lookup(winrt::box_value(L"ResourcePillRadius")));
    return a.radius;
}
void ApplyRoundedGraphClip(Canvas const& canvas, double radius) {
    double width = canvas.Width(), height = canvas.Height();
    float r = float(std::clamp(radius, 0.0, std::min(width, height) / 2));
    auto visual = winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(canvas);
    auto compositor = visual.Compositor();
    auto rounded = compositor.CreateRoundedRectangleGeometry();
    rounded.Size({float(width), float(height)});
    rounded.CornerRadius({r, r});
    visual.Clip(compositor.CreateGeometricClip(rounded));
}
void StyleResourceFlyout(Flyout const& flyout, AppearanceConfig const& a, double width, double height) {
    Style style{winrt::xaml_typename<FlyoutPresenter>()};
    // Native placement already adds a four-DIP target gap. Apply the user's
    // gap through the target coordinates; presenter margins are asymmetric
    // under Top/Bottom placement and must not add another offset.
    style.Setters().Append(Setter(FrameworkElement::MarginProperty(), winrt::box_value(Thickness{0, 0, 0, 0})));
    // FlyoutPresenter owns a native ScrollViewer even when our content does not.
    style.Setters().Append(Setter(ScrollViewer::VerticalScrollBarVisibilityProperty(), winrt::box_value(ScrollBarVisibility::Disabled)));
    style.Setters().Append(Setter(ScrollViewer::HorizontalScrollBarVisibilityProperty(), winrt::box_value(ScrollBarVisibility::Disabled)));
    style.Setters().Append(Setter(ScrollViewer::VerticalScrollModeProperty(), winrt::box_value(ScrollMode::Disabled)));
    style.Setters().Append(Setter(ScrollViewer::HorizontalScrollModeProperty(), winrt::box_value(ScrollMode::Disabled)));
    style.Setters().Append(Setter(Control::BorderThicknessProperty(), winrt::box_value(Thickness{1, 1, 1, 1})));
    style.Setters().Append(Setter(FrameworkElement::WidthProperty(), winrt::box_value(width)));
    style.Setters().Append(Setter(FrameworkElement::MaxWidthProperty(), winrt::box_value(width)));
    style.Setters().Append(Setter(FrameworkElement::HeightProperty(), winrt::box_value(height)));
    style.Setters().Append(Setter(FrameworkElement::MaxHeightProperty(), winrt::box_value(height)));
    double radius = ResourceFlyoutRadius(flyout, a);
    style.Setters().Append(Setter(Control::CornerRadiusProperty(), winrt::box_value(CornerRadius{radius, radius, radius, radius})));
    style.Setters().Append(Setter(Control::PaddingProperty(), winrt::box_value(Thickness{16, 16, 16, 16})));
    style.Setters().Append(Setter(Control::BackgroundProperty(), SolidColorBrush(a.background)));
    style.Setters().Append(Setter(Control::ForegroundProperty(), SolidColorBrush(a.identifierColor)));
    auto border = a.borderColor;
    border.A = 51;
    style.Setters().Append(Setter(Control::BorderBrushProperty(), SolidColorBrush(border)));
    flyout.FlyoutPresenterStyle(style);
}
void FitResourceFlyoutContent(Flyout const& flyout) {
    auto root = flyout.Content().try_as<Grid>();
    if (!root) return;
    auto body = FindFlyoutPart(root, L"CpuFlyoutBody").try_as<StackPanel>();
    auto footer = FindFlyoutPart(root, L"CpuFlyoutFooter").try_as<Grid>();
    auto processes = FindFlyoutPart(root, L"CpuFlyoutProcesses").try_as<StackPanel>();
    if (!body || !footer || !processes) return;
    double limit = winrt::unbox_value<double>(root.Resources().Lookup(winrt::box_value(L"FlyoutHeightLimit")));
    double preferred = winrt::unbox_value<double>(root.Resources().Lookup(winrt::box_value(L"FlyoutPreferredHeight")));
    bool network = root.Name() == L"NetworkResourceFlyout";
    int count = network ? 0 : flyoutTopCount.load();
    for (uint32_t i = 0; i < processes.Children().Size(); ++i) {
        auto row = processes.Children().GetAt(i).as<FrameworkElement>();
        auto visibility = !network && i < unsigned(count) ? Visibility::Visible : Visibility::Collapsed;
        if (row.Visibility() != visibility) row.Visibility(visibility);
    }
    body.Measure({float(root.Width()), 10000});
    footer.Measure({float(root.Width()), 10000});
    double desired = body.DesiredSize().Height + footer.DesiredSize().Height + 36;
    // On unusually short work areas, show fewer ranked rows rather than clip
    // the footer or introduce a scrollbar. The configured count stays intact.
    int omitted = 0;
    while (!network && desired > limit && count > 0) {
        processes.Children().GetAt(--count).as<FrameworkElement>().Visibility(Visibility::Collapsed);
        ++omitted;
        body.Measure({float(root.Width()), 10000});
        desired = body.DesiredSize().Height + footer.DesiredSize().Height + 36;
    }
    auto caption = FindFlyoutPart(root, L"CpuFlyoutTopCaption").try_as<TextBlock>();
    if (caption) {
        caption.Visibility(network ? Visibility::Collapsed : Visibility::Visible);
        caption.Text(omitted ? L"Top processes · limited by screen height" : L"Top processes");
    }
    double height = std::min(limit, std::max(preferred, desired));
    if (std::abs(root.Height() - (height - 36)) > 0.1) {
        root.Height(height - 36);
        StyleResourceFlyout(flyout, GetAppearance(), root.Width() + 36, height);
    }
}
int FlyoutResource(Grid const& root) {
    return root ? winrt::unbox_value_or<int>(root.Resources().Lookup(winrt::box_value(L"ResourceIndex")), 0) : 0;
}
void RefreshResourceFlyout(Flyout const& flyout) {
    auto root = flyout.Content().try_as<Grid>();
    if (!root) return;
    int resource = FlyoutResource(root);
    bool memory = resource == 1;
    bool gpu = resource == 2;
    bool network = resource == 3;
    auto setText = [&](wchar_t const* part, std::wstring const& text) {
        auto element = FindFlyoutPart(root, part).try_as<TextBlock>();
        if (element && element.Text() != text) element.Text(text);
    };
    if (network) {
        auto snapshot = ReadNetworkSnapshot();
        setText(L"NetworkFlyoutAdapter", snapshot.adapter.empty() ? L"Adapter unavailable" : snapshot.adapter);
        setText(L"NetworkFlyoutUpload", FormatRate(snapshot.rates.upload));
        setText(L"NetworkFlyoutDownload", FormatRate(snapshot.rates.download));
    } else if (gpu) {
        gpuDetailDemandUntil = GetTickCount64() + 3000;
        auto details = ReadGpuDetails();
        setText(L"GpuFlyoutHardware", details.name.empty() ? L"Adapter unavailable" : details.name);
        setText(L"GpuFlyoutDedicated", GpuMemoryAmount(details.dedicated, details.dedicatedTotal));
        setText(L"GpuFlyoutShared", GpuMemoryAmount(details.shared, details.sharedTotal));
        setText(L"GpuFlyoutTotal", GpuMemoryAmount(details.dedicated < 0 || details.shared < 0 ? -1 : details.dedicated + details.shared,
            details.dedicatedTotal + details.sharedTotal));
        auto processes = FindFlyoutPart(root, L"CpuFlyoutProcesses").try_as<StackPanel>();
        if (processes) for (uint32_t i = 0; i < processes.Children().Size(); ++i) {
            auto row = processes.Children().GetAt(i).as<Grid>();
            auto name = row.Children().GetAt(0).as<TextBlock>();
            auto value = row.Children().GetAt(1).as<TextBlock>();
            std::wstring label = i < details.processes.size() ? details.processes[i].name + L" (" + std::to_wstring(details.processes[i].pid) + L")" :
                (i == 0 ? (details.ready ? L"No readable GPU process samples" : L"Sampling GPU processes…") : L"");
            wchar_t percent[32] = L"--";
            if (i < details.processes.size()) swprintf_s(percent, L"%.1f%%", details.processes[i].percent);
            if (name.Text() != label) name.Text(label);
            if (value.Text() != percent) value.Text(percent);
        }
    } else if (memory) {
        memoryDetailDemandUntil = GetTickCount64() + 3000;
        auto details = ReadMemoryDetails();
        setText(L"MemoryFlyoutHardware", details.hardware);
        setText(L"MemoryFlyoutUsed", details.total ? MemoryAmount(details.total - std::min(details.total, details.available), true) : L"-- GB");
        setText(L"MemoryFlyoutAvailable", details.total ? MemoryAmount(details.available, true) : L"-- GB");
        auto processes = FindFlyoutPart(root, L"CpuFlyoutProcesses").try_as<StackPanel>();
        if (processes) for (uint32_t i = 0; i < processes.Children().Size(); ++i) {
            auto row = processes.Children().GetAt(i).as<Grid>();
            auto name = row.Children().GetAt(0).as<TextBlock>();
            auto value = row.Children().GetAt(1).as<TextBlock>();
            std::wstring label = i < details.processes.size() ? details.processes[i].name + L" (" + std::to_wstring(details.processes[i].pid) + L")" :
                (i == 0 ? (details.ready ? L"No readable process samples" : L"Sampling processes…") : L"");
            auto amount = i < details.processes.size() ? MemoryAmount(details.processes[i].bytes) : L"--";
            if (name.Text() != label) name.Text(label);
            if (value.Text() != amount) value.Text(amount);
        }
    } else {
        cpuDetailDemandUntil = GetTickCount64() + 3000;
        auto details = ReadCpuDetails();
        auto speed = FindFlyoutPart(root, L"CpuFlyoutClock").try_as<TextBlock>();
        if (speed) {
            wchar_t buffer[32];
            if (details.ghz > 0) swprintf_s(buffer, L"%.2f GHz", details.ghz);
            else wcscpy_s(buffer, L"-- GHz");
            if (speed.Text() != buffer) speed.Text(buffer);
        }
        auto processes = FindFlyoutPart(root, L"CpuFlyoutProcesses").try_as<StackPanel>();
        if (processes) for (uint32_t i = 0; i < processes.Children().Size(); ++i) {
            auto row = processes.Children().GetAt(i).as<Grid>();
            auto name = row.Children().GetAt(0).as<TextBlock>();
            auto value = row.Children().GetAt(1).as<TextBlock>();
            std::wstring label = i < details.processes.size() ? details.processes[i].name + L" (" + std::to_wstring(details.processes[i].pid) + L")" :
                (i == 0 ? (details.ready ? L"No readable process samples" : L"Sampling processes…") : L"");
            wchar_t percent[32] = L"--";
            if (i < details.processes.size()) swprintf_s(percent, L"%.1f%%", details.processes[i].percent);
            if (name.Text() != label) name.Text(label);
            if (value.Text() != percent) value.Text(percent);
        }
    }
    FitResourceFlyoutContent(flyout);
    auto a = GetAppearance();
    if (winrt::unbox_value_or<unsigned>(root.Tag(), 0) != a.revision) {
        StyleResourceFlyout(flyout, a, root.Width() + 36, root.Height() + 36);
        RefreshFlyoutForeground(root, a.identifierColor);
        auto frame = FindFlyoutPart(root, L"CpuFlyoutGraphBorder").try_as<Border>();
        auto graph = FindFlyoutPart(root, L"CpuFlyoutGraph").try_as<Canvas>();
        double radius = ResourceFlyoutRadius(flyout, a);
        if (frame) {
            frame.CornerRadius({radius, radius, radius, radius});
            SolidColorBrush border(a.borderColor);
            border.Opacity(a.borderOpacity);
            frame.BorderBrush(border);
        }
        if (graph) ApplyRoundedGraphClip(graph, std::max(0.0, radius - 1));
        root.Tag(winrt::box_value(a.revision));
    }
    auto utilization = FindFlyoutPart(root, L"CpuFlyoutUtilization").try_as<TextBlock>();
    int percent = gpu ? gpuPercent.load() : memory ? ramPercent.load() : cpuPercent.load();
    auto value = percent < 0 ? std::wstring(L"--%") : std::to_wstring(percent) + L"%";
    if (!network && utilization && utilization.Text() != value) utilization.Text(value);
    auto canvas = FindFlyoutPart(root, L"CpuFlyoutGraph").try_as<Canvas>();
    if (!canvas) return;
    double width = canvas.Width(), height = canvas.Height();
    canvas.Children().Clear();
    for (int i = 0; i <= 4; ++i) {
        winrt::Windows::UI::Xaml::Shapes::Line gridLine;
        gridLine.X1(0); gridLine.X2(width);
        gridLine.Y1(i * (height - 2) / 4 + 1); gridLine.Y2(gridLine.Y1());
        gridLine.Stroke(SolidColorBrush(a.identifierColor));
        gridLine.StrokeThickness(1);
        gridLine.Opacity(0.12);
        canvas.Children().Append(gridLine);
    }
    AcquireSRWLockShared(&historyLock);
    auto history = graphHistory;
    ReleaseSRWLockShared(&historyLock);
    auto now = GetTickCount64();
    double networkMax = 1;
    if (resource == 3) for (auto const& sample : history) {
        if (now - sample.time <= 60000)
            networkMax = std::max(networkMax, std::max(sample.values[3], sample.values[4]));
    }
    networkMax *= 1.1;
    auto drawSeries = [&](unsigned metric, winrt::Windows::UI::Color color, double scale) {
        winrt::Windows::UI::Xaml::Shapes::Polyline line{nullptr};
        winrt::Windows::UI::Xaml::Shapes::Polygon area{nullptr};
        float lastX = 0;
        auto finishArea = [&] {
            if (area) area.Points().Append(winrt::Windows::Foundation::Point{lastX, float(height - 1)});
            area = nullptr;
        };
        ULONGLONG previous = 0;
        for (auto const& sample : history) {
            if (now - sample.time > 60000) continue;
            double value = sample.values[metric];
            if (!std::isfinite(value) || value < 0) { finishArea(); line = nullptr; previous = 0; continue; }
            if (!line || (previous && sample.time - previous > 2500)) {
                finishArea();
                if (a.fillAlpha) {
                    area = winrt::Windows::UI::Xaml::Shapes::Polygon();
                    auto fill = color; fill.A = a.fillAlpha;
                    area.Fill(SolidColorBrush(fill));
                    canvas.Children().Append(area);
                }
                line = winrt::Windows::UI::Xaml::Shapes::Polyline();
                line.Stroke(SolidColorBrush(color));
                line.StrokeThickness(1.5);
                canvas.Children().Append(line);
            }
            float x = float(1 + (width - 2) * (1 - double(now - sample.time) / 60000));
            float y = float(height - 1 - (height - 2) * std::clamp(value / scale, 0.0, 1.0));
            if (area) {
                if (!area.Points().Size()) area.Points().Append(winrt::Windows::Foundation::Point{x, float(height - 1)});
                area.Points().Append(winrt::Windows::Foundation::Point{x, y});
            }
            line.Points().Append(winrt::Windows::Foundation::Point{x, y});
            lastX = x;
            previous = sample.time;
        }
        finishArea();
    };
    if (resource == 3) {
        drawSeries(3, a.graphColor, networkMax);       // Upload
        drawSeries(4, a.identifierColor, networkMax);  // Download
    } else {
        drawSeries(unsigned(resource), a.graphColor, 100.0);
    }
}
void UpdateResourceFlyouts() {
    auto group = activeInstance->group.get();
    if (!group) return;
    for (uint32_t i = 0; i < std::min<uint32_t>(5, group.Children().Size()); ++i) {
        auto anchor = group.Children().GetAt(i).as<Border>();
        auto flyout = primitives::FlyoutBase::GetAttachedFlyout(anchor).try_as<Flyout>();
        if (flyout && flyout.IsOpen()) RefreshResourceFlyout(flyout);
    }
}
double ClampFlyoutCenter(double preferred, double workLeft, double workRight, double width, double margin) {
    double half = width / 2;
    double left = workLeft + margin + half, right = workRight - margin - half;
    return left <= right ? std::clamp(preferred, left, right) : (workLeft + workRight) / 2;
}
double ResourceFlyoutTargetEdge(double taskbarEdge, double gap, bool top) {
    constexpr double nativeFlyoutGap = 4;
    return taskbarEdge + (top ? 1 : -1) * (gap - nativeFlyoutGap);
}
double ResourceFlyoutTaskbarEdge(UIElement const& root, double fallback, bool top) {
    // Taskbar HWND bounds can include space outside the styled visible bar.
    // Measure the same background used by automatic pill height instead.
    struct Node { DependencyObject object; int depth; };
    std::vector<Node> pending{{root, 0}};
    int visited = 0;
    while (!pending.empty() && visited++ < 350) {
        auto node = pending.back(); pending.pop_back();
        auto element = node.object.try_as<FrameworkElement>();
        if (element && element.Name() == L"BackgroundControl" &&
            winrt::get_class_name(node.object) == L"Taskbar.TaskbarBackground" &&
            element.Visibility() == Visibility::Visible && element.ActualHeight() > 0) {
            auto bounds = element.TransformToVisual(root).TransformBounds(winrt::Windows::Foundation::Rect{
                0, 0, float(element.ActualWidth()), float(element.ActualHeight())});
            double edge = top ? bounds.Y + bounds.Height : bounds.Y;
            if (std::isfinite(edge)) return edge;
        }
        if (node.depth >= 12) continue;
        for (int i = VisualTreeHelper::GetChildrenCount(node.object) - 1; i >= 0; --i)
            pending.push_back({VisualTreeHelper::GetChild(node.object, i), node.depth + 1});
    }
    return fallback;
}
FrameworkElement ResourceFlyoutPlacementTarget(Border const& anchor, HWND hwnd, double width, bool top) {
    auto layout = anchor.Child().try_as<Grid>();
    if (!layout || layout.Children().Size() < 6) return anchor;
    auto marker = layout.Children().GetAt(5).try_as<Border>();
    auto xamlRoot = anchor.XamlRoot();
    auto root = xamlRoot ? xamlRoot.Content().try_as<UIElement>() : nullptr;
    if (!marker || !root) return anchor;
    POINT origin{};
    RECT taskbar{};
    MONITORINFO monitor{sizeof(monitor)};
    if (!ClientToScreen(hwnd, &origin) || !GetWindowRect(hwnd, &taskbar) ||
        !GetMonitorInfoW(MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST), &monitor)) return anchor;
    double scale = xamlRoot.RasterizationScale();
    if (scale <= 0) return anchor;
    auto bounds = anchor.TransformToVisual(root).TransformBounds(winrt::Windows::Foundation::Rect{
        0, 0, float(anchor.ActualWidth()), float(anchor.ActualHeight())});
    double center = ClampFlyoutCenter(bounds.X + bounds.Width / 2,
        (monitor.rcWork.left - origin.x) / scale, (monitor.rcWork.right - origin.x) / scale,
        width, flyoutScreenMargin.load());
    auto transform = marker.TransformToVisual(root);
    auto markerBounds = transform.TransformBounds(winrt::Windows::Foundation::Rect{
        0, 0, float(marker.ActualWidth()), float(marker.ActualHeight())});
    auto inverse = transform.Inverse();
    if (!inverse) return anchor;
    double edge = ResourceFlyoutTaskbarEdge(root,
        ((top ? taskbar.bottom : taskbar.top) - origin.y) / scale, top);
    edge = ResourceFlyoutTargetEdge(edge, flyoutGap.load(), top);
    // Every resource shares the same taskbar-facing baseline. The one-DIP
    // marker is already part of the pill: no child/resource mutations at open.
    auto delta = inverse.TransformPoint({float(center - markerBounds.Width / 2),
        float(top ? edge - markerBounds.Height : edge)});
    auto shift = marker.RenderTransform().as<TranslateTransform>();
    shift.X(shift.X() + delta.X);
    shift.Y(shift.Y() + delta.Y);
    marker.CornerRadius(anchor.CornerRadius());
    return marker;
}
void StopResourceHoverTimer(Border const& anchor);
void DetachFlyoutHover(Flyout const& flyout);
void DetachPillHandlers(Border const& anchor);
void CloseResourceFlyout(Border const& anchor) {
    StopResourceHoverTimer(anchor);
    if (auto flyout = primitives::FlyoutBase::GetAttachedFlyout(anchor)) {
        if (auto typed = flyout.try_as<Flyout>()) DetachFlyoutHover(typed);
        flyout.OverlayInputPassThroughElement(nullptr);
        flyout.AreOpenCloseAnimationsEnabled(false);
        flyout.Hide();
        primitives::FlyoutBase::SetAttachedFlyout(anchor, nullptr);
    }
}
void CloseResourceFlyouts(StackPanel const& group) {
    if (!group) return;
    for (uint32_t i = 0; i < std::min<uint32_t>(5, group.Children().Size()); ++i)
    {
        auto anchor = group.Children().GetAt(i).as<Border>();
        CloseResourceFlyout(anchor);
        DetachPillHandlers(anchor);
    }
}
Flyout BuildResourceFlyout(double width, double height, double radius, double heightLimit, bool taskbarAtTop, int resource) {
    bool memory = resource == 1, gpu = resource == 2, network = resource == 3;
    Flyout flyout;
    flyout.ShouldConstrainToRootBounds(false);
    flyout.AreOpenCloseAnimationsEnabled(flyoutAnimations.load());
    // 32 DIP padding + 2 DIP border + 2 DIP layout-rounding allowance.
    double contentWidth = width - 36;
    Grid root;
    root.Name(network ? L"NetworkResourceFlyout" : gpu ? L"GpuResourceFlyout" : memory ? L"MemoryResourceFlyout" : L"CpuResourceFlyout");
    root.Resources().Insert(winrt::box_value(L"ResourceIndex"), winrt::box_value(resource));
    root.Resources().Insert(winrt::box_value(L"FlyoutTaskbarAtTop"), winrt::box_value(taskbarAtTop));
    root.Resources().Insert(winrt::box_value(L"ResourcePillRadius"), winrt::box_value(radius));
    root.Resources().Insert(winrt::box_value(L"FlyoutHeightLimit"), winrt::box_value(heightLimit));
    root.Resources().Insert(winrt::box_value(L"FlyoutPreferredHeight"), winrt::box_value(height));
    root.Width(contentWidth);
    root.Height(height - 36);
    RowDefinition mainRow; mainRow.Height({1, GridUnitType::Star});
    RowDefinition footerRow; footerRow.Height({1, GridUnitType::Auto});
    root.RowDefinitions().Append(mainRow);
    root.RowDefinitions().Append(footerRow);
    StackPanel body;
    body.Name(L"CpuFlyoutBody");
    body.Margin({4, 0, 4, 0});
    body.Spacing(8);
    Grid title;
    ColumnDefinition titleColumn; titleColumn.Width({1, GridUnitType::Auto});
    ColumnDefinition nameColumn; nameColumn.Width({1, GridUnitType::Star});
    title.ColumnDefinitions().Append(titleColumn); title.ColumnDefinitions().Append(nameColumn);
    StackPanel titleLeft;
    titleLeft.Orientation(Orientation::Horizontal);
    titleLeft.Spacing(8);
    auto cpuIcon = MakeIcon(network ? L"\uE774" : gpu ? L"\uE950" : memory ? L"\uE964" : L"\uE9D9");
    cpuIcon.as<FontIcon>().Foreground(SolidColorBrush(GetAppearance().identifierColor));
    titleLeft.Children().Append(cpuIcon);
    auto heading = FlyoutText(network ? L"Network" : gpu ? L"GPU" : memory ? L"Memory" : L"CPU", 16);
    heading.FontWeight(winrt::Windows::UI::Text::FontWeight{600});
    titleLeft.Children().Append(heading);
    title.Children().Append(titleLeft);
    auto processor = FlyoutText(resource ? L"" : ResourceCpuName().c_str(), 11);
    if (resource) processor.Name(network ? L"NetworkFlyoutAdapter" : gpu ? L"GpuFlyoutHardware" : L"MemoryFlyoutHardware");
    processor.TextTrimming(TextTrimming::CharacterEllipsis);
    processor.TextAlignment(TextAlignment::Right);
    processor.VerticalAlignment(VerticalAlignment::Center);
    processor.Margin({16, 0, 0, 0});
    Grid::SetColumn(processor, 1);
    title.Children().Append(processor);
    body.Children().Append(title);
    Canvas graph;
    graph.Name(L"CpuFlyoutGraph");
    // Full inset content width, allowing one pixel per graph-border side.
    graph.Width(contentWidth - 10);
    graph.Height(flyoutGraphHeight.load() - 2);
    ApplyRoundedGraphClip(graph, std::max(0.0, radius - 1));
    Border graphBorder;
    graphBorder.Name(L"CpuFlyoutGraphBorder");
    graphBorder.CornerRadius({radius, radius, radius, radius});
    graphBorder.BorderThickness({1, 1, 1, 1});
    auto appearance = GetAppearance();
    SolidColorBrush graphBorderBrush(appearance.borderColor);
    graphBorderBrush.Opacity(appearance.borderOpacity);
    graphBorder.BorderBrush(graphBorderBrush);
    graphBorder.Child(graph);
    body.Children().Append(graphBorder);
    Grid info;
    if (network) {
        for (int i = 0; i < 2; ++i) {
            ColumnDefinition column; column.Width({1, GridUnitType::Star});
            info.ColumnDefinitions().Append(column);
            StackPanel block;
            Grid::SetColumn(block, i);
            auto label = FlyoutText(i == 0 ? L"Upload" : L"Download", 11);
            auto value = FlyoutText(L"--", 18);
            value.Name(i == 0 ? L"NetworkFlyoutUpload" : L"NetworkFlyoutDownload");
            if (i == 1) { label.TextAlignment(TextAlignment::Right); value.TextAlignment(TextAlignment::Right); }
            block.Children().Append(label);
            block.Children().Append(value);
            info.Children().Append(block);
        }
    } else if (gpu) {
        wchar_t const* labels[] = {L"Dedicated memory", L"Shared memory", L"GPU memory", L"Utilization"};
        wchar_t const* parts[] = {L"GpuFlyoutDedicated", L"GpuFlyoutShared", L"GpuFlyoutTotal", L"CpuFlyoutUtilization"};
        for (int i = 0; i < 4; ++i) {
            ColumnDefinition column; column.Width({1, GridUnitType::Star});
            info.ColumnDefinitions().Append(column);
            StackPanel block; Grid::SetColumn(block, i);
            auto label = FlyoutText(labels[i], 11);
            auto value = FlyoutText(i == 3 ? L"--%" : L"-- / -- GB", 16);
            value.Name(parts[i]);
            if (i >= 2) { label.TextAlignment(TextAlignment::Right); value.TextAlignment(TextAlignment::Right); }
            block.Children().Append(label); block.Children().Append(value);
            info.Children().Append(block);
        }
    } else if (memory) {
        wchar_t const* labels[] = {L"In use", L"Available", L"Utilization"};
        wchar_t const* parts[] = {L"MemoryFlyoutUsed", L"MemoryFlyoutAvailable", L"CpuFlyoutUtilization"};
        for (int i = 0; i < 3; ++i) {
            ColumnDefinition column; column.Width({1, GridUnitType::Star});
            info.ColumnDefinitions().Append(column);
            StackPanel block;
            Grid::SetColumn(block, i);
            auto label = FlyoutText(labels[i], 11);
            auto value = FlyoutText(i == 2 ? L"--%" : L"-- GB", 18);
            value.Name(parts[i]);
            if (i == 2) { label.TextAlignment(TextAlignment::Right); value.TextAlignment(TextAlignment::Right); }
            block.Children().Append(label); block.Children().Append(value);
            info.Children().Append(block);
        }
    } else {
        for (int i = 0; i < 2; ++i) {
            ColumnDefinition column; column.Width({1, GridUnitType::Star});
            info.ColumnDefinitions().Append(column);
        }
        StackPanel usage;
        usage.Children().Append(FlyoutText(L"Utilization", 11));
        auto utilization = FlyoutText(L"--%", 18);
        utilization.Name(L"CpuFlyoutUtilization");
        usage.Children().Append(utilization);
        info.Children().Append(usage);
        StackPanel speed;
        Grid::SetColumn(speed, 1);
        auto speedLabel = FlyoutText(L"Clock speed", 11);
        speedLabel.TextAlignment(TextAlignment::Right);
        auto speedValue = FlyoutText(L"-- GHz", 18);
        speedValue.Name(L"CpuFlyoutClock");
        speedValue.TextAlignment(TextAlignment::Right);
        speed.Children().Append(speedLabel);
        speed.Children().Append(speedValue);
        info.Children().Append(speed);
    }
    body.Children().Append(info);
    auto topCaption = FlyoutText(network ? L"" : L"Top processes", 12);
    topCaption.Name(L"CpuFlyoutTopCaption");
    if (network) topCaption.Visibility(Visibility::Collapsed);
    body.Children().Append(topCaption);
    StackPanel processes;
    processes.Name(L"CpuFlyoutProcesses");
    if (network) processes.Visibility(Visibility::Collapsed);
    for (int i = 0; i < 10; ++i) {
        Grid row;
        row.Height(22);
        ColumnDefinition label; label.Width({1, GridUnitType::Star});
        ColumnDefinition value; value.Width({1, GridUnitType::Auto});
        row.ColumnDefinitions().Append(label); row.ColumnDefinitions().Append(value);
        auto process = FlyoutText(i == 0 ? L"Sampling processes…" : L"");
        process.TextTrimming(TextTrimming::CharacterEllipsis);
        process.Margin({0, 0, 12, 0});
        row.Children().Append(process);
        auto amount = FlyoutText(L"--");
        amount.TextAlignment(TextAlignment::Right);
        Grid::SetColumn(amount, 1);
        row.Children().Append(amount);
        row.Visibility(i < flyoutTopCount ? Visibility::Visible : Visibility::Collapsed);
        processes.Children().Append(row);
    }
    body.Children().Append(processes);
    root.Children().Append(body);
    Grid footer;
    footer.Name(L"CpuFlyoutFooter");
    footer.Margin({4, 8, 4, 0});
    Grid::SetRow(footer, 1);
    ColumnDefinition label; label.Width({1, GridUnitType::Star});
    ColumnDefinition action; action.Width({1, GridUnitType::Auto});
    footer.ColumnDefinitions().Append(label); footer.ColumnDefinitions().Append(action);
    HyperlinkButton taskManager;
    taskManager.Content(winrt::box_value(L"Open Task Manager"));
    taskManager.Padding({10, 6, 10, 6});
    taskManager.Background(nullptr);
    taskManager.BorderThickness({0, 0, 0, 0});
    taskManager.BorderBrush(nullptr);
    // Keep native link behavior and keyboard focus, with no painted button fill.
    for (auto key : {L"HyperlinkButtonBackground", L"HyperlinkButtonBackgroundPointerOver",
                     L"HyperlinkButtonBackgroundPressed", L"HyperlinkButtonBackgroundDisabled",
                     L"HyperlinkButtonBorderBrush", L"HyperlinkButtonBorderBrushPointerOver",
                     L"HyperlinkButtonBorderBrushPressed"})
        taskManager.Resources().Insert(winrt::box_value(key), SolidColorBrush(winrt::Windows::UI::Color{0, 0, 0, 0}));
    Grid::SetColumn(taskManager, 1);
    taskManager.Click([](auto const&, auto const&) { OpenResourceTaskManager(); });
    footer.Children().Append(taskManager);
    root.Children().Append(footer);
    root.KeyDown([](auto const&, input::KeyRoutedEventArgs const& args) {
        if (args.Key() == winrt::Windows::System::VirtualKey::Enter) {
            // Let the native button handle its own Enter key once.
            if (!args.OriginalSource().try_as<Control>()) {
                args.Handled(true);
                OpenResourceTaskManager();
            }
        }
    });
    flyout.Content(root);
    StyleResourceFlyout(flyout, GetAppearance(), width, height);
    FitResourceFlyoutContent(flyout);
    return flyout;
}
void BindFlyoutHover(Flyout const& flyout, HWND hwnd, unsigned resource);
void ShowResourceFlyout(Border anchor, HWND hwnd, bool hover, int resource = 0) {
    if (resource == 3 || resource == 4) {
        auto group = VisualTreeHelper::GetParent(anchor).try_as<StackPanel>();
        uint32_t index = 0;
        if (group && group.Children().IndexOf(anchor, index) && index == 4 && group.Children().Size() > 3)
            anchor = group.Children().GetAt(3).as<Border>();
        resource = 3;
    }
    bool memory = resource == 1, gpu = resource == 2, network = resource == 3;
    if (stopping || (gpu ? !showGpu : memory ? !showRam : network ? !showNetwork : !showCpu)) return;
    auto existing = primitives::FlyoutBase::GetAttachedFlyout(anchor).try_as<Flyout>();
    if (existing && existing.IsOpen()) {
        if (!hover) existing.Hide();
        return;
    }
    // Replace an older resource flyout only once this opening is committed.
    // Merely brushing another pill does not release a click-kept flyout.
    auto group = VisualTreeHelper::GetParent(anchor).try_as<StackPanel>();
    if (group) for (uint32_t i = 0; i < group.Children().Size(); ++i) {
        auto other = group.Children().GetAt(i).try_as<Border>();
        if (!other || other == anchor) continue;
        if (auto old = primitives::FlyoutBase::GetAttachedFlyout(other)) {
            CloseResourceFlyout(other);
        }
    }
    if (existing) DetachFlyoutHover(existing);
    // Recreate only on explicit opening, so settings and themes are reflected
    // without leaving cached flyout projections or handler cycles behind.
    MONITORINFO monitor{sizeof(monitor)};
    GetMonitorInfoW(MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST), &monitor);
    UINT dpi = GetDpiForWindow(hwnd);
    double scale = (dpi ? dpi : 96) / 96.0;
    double availableWidth = (monitor.rcWork.right - monitor.rcWork.left) / scale - 2 * flyoutScreenMargin.load() - 16;
    double availableHeight = (monitor.rcWork.bottom - monitor.rcWork.top) / scale - flyoutScreenMargin.load() - 16 - flyoutGap.load();
    double width = std::min(double(flyoutWidth.load()), std::max(240.0, availableWidth));
    double height = std::min(double(flyoutHeight.load()), std::max(200.0, availableHeight));
    RECT taskbar{}; GetWindowRect(hwnd, &taskbar);
    bool top = taskbar.top < (monitor.rcMonitor.top + monitor.rcMonitor.bottom) / 2;
    auto flyout = BuildResourceFlyout(width, height, anchor.CornerRadius().TopLeft, std::max(200.0, availableHeight), top, resource);
    BindFlyoutHover(flyout, hwnd, unsigned(resource));
    flyout.XamlRoot(anchor.XamlRoot());
    // Keep sibling pills available to hover even under a click-opened flyout's overlay.
    if (group) flyout.OverlayInputPassThroughElement(group);
    flyout.Placement(top ? primitives::FlyoutPlacementMode::Bottom : primitives::FlyoutPlacementMode::Top);
    flyout.ShowMode(hover ? primitives::FlyoutShowMode::Transient : primitives::FlyoutShowMode::Standard);
    primitives::FlyoutBase::SetAttachedFlyout(anchor, flyout);
    RefreshResourceFlyout(flyout);
    auto target = ResourceFlyoutPlacementTarget(anchor, hwnd, width, top);
    try {
        flyout.ShowAt(target);
    } catch (winrt::hresult_error const& error) {
        if (target == anchor) throw;
        Wh_Log(L"SSR: placement anchor failed 0x%08X: %s; using pill anchor",
            unsigned(error.code()), error.message().c_str());
        flyout.ShowAt(anchor);
    }
}

// Message-only timer delivery: queued WM_TIMER messages contain no pointer into
// this mod. The window subclass is removed on its owning UI thread before unload.
UINT HoverTimerId() {
    static UINT id = RegisterWindowMessageW(L"SimpleSystemResourcesHover_" WH_MOD_ID);
    return id;
}
LRESULT CALLBACK ResourceHoverSubclass(HWND hwnd, UINT message, WPARAM wp, LPARAM lp, UINT_PTR id, DWORD_PTR data);
void StopNativeHover(HWND hwnd, bool detach) {
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end()) return;
    auto& instance = *found->second;
    if (instance.hoverTimer) KillTimer(hwnd, HoverTimerId());
    instance.hoverTimer = false;
    if (detach && instance.hoverSubclass) {
        BOOL removed = RemoveWindowSubclass(hwnd, ResourceHoverSubclass, HoverTimerId());
        if (!removed) Wh_Log(L"SSR: hover subclass removal failed hwnd=%p", hwnd);
        instance.hoverSubclass = false;
    }
}
void StopResourceHoverTimer(Border const& anchor) {
    auto resources = anchor.Resources();
    auto key = winrt::box_value(L"SSRHoverWindow");
    if (!resources.HasKey(key)) return;
    HWND hwnd = reinterpret_cast<HWND>(uintptr_t(winrt::unbox_value<uint64_t>(resources.Lookup(key))));
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end()) return;
    unsigned index = winrt::unbox_value<unsigned>(resources.Lookup(winrt::box_value(L"SSRHoverResource")));
    found->second->hover[index].Dismiss();
    for (auto const& state : found->second->hover) if (state.pending || state.hoverOpened) return;
    StopNativeHover(hwnd, false);
}
Border ResolveHoverAnchor(HWND hwnd, unsigned resource) {
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end()) return nullptr;
    auto group = found->second->group.get();
    if (!group) {
        auto attached = FindAttachedPills(TaskbarRoot(hwnd));
        group = attached.group;
    }
    if (!group || resource >= group.Children().Size()) return nullptr;
    return group.Children().GetAt(resource).try_as<Border>();
}
// Native popup creation can change XAML hit testing without cursor movement.
// Use the taskbar's XAML transform and rasterization scale to verify a pill exit.
bool CursorOverResourcePill(Border const& anchor, HWND hwnd) {
    if (!IsWindowVisible(hwnd) || anchor.Visibility() != Visibility::Visible ||
        anchor.ActualWidth() <= 0 || anchor.ActualHeight() <= 0) return false;
    auto xamlRoot = anchor.XamlRoot();
    if (!xamlRoot) return false;
    auto root = xamlRoot.Content().try_as<UIElement>();
    if (!root) return false;
    auto bounds = anchor.TransformToVisual(root).TransformBounds(winrt::Windows::Foundation::Rect{
        0, 0, float(anchor.ActualWidth()), float(anchor.ActualHeight())});
    POINT origin{}, cursor{};
    if (!ClientToScreen(hwnd, &origin) || !GetCursorPos(&cursor)) return false;
    double scale = xamlRoot.RasterizationScale();
    double x = (cursor.x - origin.x) / scale, y = (cursor.y - origin.y) / scale;
    auto contains = [&](Border const& pill) {
        if (!pill || pill.Visibility() != Visibility::Visible || pill.ActualWidth() <= 0 || pill.ActualHeight() <= 0) return false;
        auto rect = pill.TransformToVisual(root).TransformBounds(winrt::Windows::Foundation::Rect{
            0, 0, float(pill.ActualWidth()), float(pill.ActualHeight())});
        return x >= rect.X && x < rect.X + rect.Width && y >= rect.Y && y < rect.Y + rect.Height;
    };
    if (x >= bounds.X && x < bounds.X + bounds.Width && y >= bounds.Y && y < bounds.Y + bounds.Height) return true;
    auto key = winrt::box_value(L"SSRHoverResource");
    if (anchor.Resources().HasKey(key) && winrt::unbox_value<unsigned>(anchor.Resources().Lookup(key)) == 3) {
        auto group = VisualTreeHelper::GetParent(anchor).try_as<StackPanel>();
        if (group && group.Children().Size() > 4)
            return contains(group.Children().GetAt(3).try_as<Border>()) || contains(group.Children().GetAt(4).try_as<Border>());
    }
    return false;
}
void ResourceHoverTick(HWND hwnd, unsigned resource) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end() || stopping) return;
    auto anchor = ResolveHoverAnchor(hwnd, resource);
    if (!anchor) { Wh_Log(L"SSR: hover tick lost anchor resource=%u", resource); found->second->hover[resource] = {}; return; }
    auto& state = found->second->hover[resource];
    auto flyout = primitives::FlyoutBase::GetAttachedFlyout(anchor).try_as<Flyout>();
    if (!flyoutOnHover || anchor.Visibility() != Visibility::Visible) {
        if (state.hoverOpened && flyout && flyout.IsOpen()) flyout.Hide();
        state = {};
        StopResourceHoverTimer(anchor);
        return;
    }
    if (state.hoverOpened) {
        bool overPill = CursorOverResourcePill(anchor, hwnd);
        if (overPill != state.overPill) {
            if (overPill) { state.overPill = true; state.outside = 0; }
            else state.Leave(GetTickCount64());
        }
        if (!state.opening && (!flyout || !flyout.IsOpen())) state.Dismiss();
        // A failed native opening must not leave a timer running indefinitely.
        if (state.opening && GetTickCount64() - state.entered > uint64_t(hoverDelay.load()) + 3000) {
            Wh_Log(L"SSR: native hover opening timed out resource=%u", resource);
            state.Dismiss();
        }
    }
    // Do not open while dragging or while a mouse button is held. A press
    // inside a hover flyout pins it for the ensuing interaction/context menu.
    bool pressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) || (GetAsyncKeyState(VK_RBUTTON) & 0x8000);
    if (pressed) {
        state.pending = false;
        if (state.overFlyout) state.Dismiss();
    }
    auto action = state.Tick(GetTickCount64(), hoverDelay.load(), hoverCloseDelay.load());
    if (action == HoverAction::Open) {
        if (flyout && flyout.IsOpen()) state.Dismiss(); // A click-opened flyout keeps its own lifetime.
        else {
            ShowResourceFlyout(anchor, hwnd, true, int(resource));
        }
    } else if (action == HoverAction::Close) {
        if (flyout && flyout.IsOpen()) flyout.Hide();
    }
    if (!state.pending && !state.hoverOpened) StopResourceHoverTimer(anchor);
}
void StartResourceHover(Border const& anchor, HWND hwnd, unsigned resource) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end() || stopping || !flyoutOnHover) return;
    if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) || (GetAsyncKeyState(VK_RBUTTON) & 0x8000)) return;
    auto& state = found->second->hover[resource];
    auto current = primitives::FlyoutBase::GetAttachedFlyout(anchor).try_as<Flyout>();
    if (current && current.IsOpen() && !state.hoverOpened) return;
    for (unsigned i = 0; i < found->second->hover.size(); ++i)
        if (i != resource) found->second->hover[i].pending = false;
    state.Enter(GetTickCount64());
    auto id = HoverTimerId();
    if (!id) { state.Dismiss(); Wh_Log(L"SSR: could not allocate hover message id"); return; }
    if (!found->second->hoverSubclass) {
        if (!SetWindowSubclass(hwnd, ResourceHoverSubclass, id, 0)) {
            state.Dismiss(); Wh_Log(L"SSR: hover subclass install failed error=%lu", GetLastError()); return;
        }
        found->second->hoverSubclass = true;
    }
    if (!found->second->hoverTimer) {
        found->second->hoverTimer = SetTimer(hwnd, id, 40, nullptr) != 0;
        if (!found->second->hoverTimer) { state.Dismiss(); Wh_Log(L"SSR: hover timer failed error=%lu", GetLastError()); return; }
    }

}
void LeaveResourceHover(Border const& anchor, HWND hwnd, unsigned resource) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end()) return;
    auto& state = found->second->hover[resource];
    if (CursorOverResourcePill(anchor, hwnd)) {
        return;
    }
    state.Leave(GetTickCount64());
    if (!state.hoverOpened) StopResourceHoverTimer(anchor);
}
void CancelResourceHover(Border const& anchor, HWND hwnd, unsigned resource) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    if (auto found = pillInstances.find(hwnd); found != pillInstances.end()) found->second->hover[resource].Dismiss();
    StopResourceHoverTimer(anchor);
}
void HandleResourceTap(Border anchor, HWND hwnd, unsigned resource) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    auto found = pillInstances.find(hwnd);
    if (found == pillInstances.end() || stopping) return;
    if (resource == 3 || resource == 4) {
        auto group = VisualTreeHelper::GetParent(anchor).try_as<StackPanel>();
        uint32_t index = 0;
        if (group && group.Children().IndexOf(anchor, index) && index == 4 && group.Children().Size() > 3)
            anchor = group.Children().GetAt(3).as<Border>();
        resource = 3;
    }
    auto& state = found->second->hover[resource];
    auto now = GetTickCount64();
    if (state.ConsumeHandledTap(now)) {
        return;
    }
    auto flyout = primitives::FlyoutBase::GetAttachedFlyout(anchor).try_as<Flyout>();
    if (state.hoverOpened && flyout) {
        // A first deliberate click adopts the hover flyout, including while
        // its opening animation is still in progress, rather than hiding it.
        state.RememberPillClick(now, true, int32_t(GetMessageTime()));
        state.pillTapConsumed = true;
        CancelResourceHover(anchor, hwnd, resource);
        return;
    }
    CancelResourceHover(anchor, hwnd, resource);
    ShowResourceFlyout(anchor, hwnd, false, int(resource));
}
LRESULT CALLBACK ResourceHoverSubclass(HWND hwnd, UINT message, WPARAM wp, LPARAM lp, UINT_PTR id, DWORD_PTR) {
    if (message == WM_NCDESTROY) {
        std::lock_guard<std::recursive_mutex> lock(instancesMutex);
        StopNativeHover(hwnd, true);
    } else if (message == WM_TIMER && wp == id && lp == 0) {
        std::lock_guard<std::recursive_mutex> lock(instancesMutex);
        try {
            auto found = pillInstances.find(hwnd);
            if (found == pillInstances.end()) return 0;
            if (stopping) { StopNativeHover(hwnd, true); return 0; }
            for (unsigned i = 0; i < 4; ++i) {
                auto const& state = found->second->hover[i];
                if (state.pending || state.hoverOpened) ResourceHoverTick(hwnd, i);
            }
            bool active = false;
            for (auto const& state : found->second->hover) active |= state.pending || state.hoverOpened;
            if (!active) StopNativeHover(hwnd, false);
        } catch (winrt::hresult_error const& e) {
            StopNativeHover(hwnd, false);
            Wh_Log(L"SSR: native hover tick failed 0x%08X", unsigned(e.code().value));
        } catch (...) {
            StopNativeHover(hwnd, false);
            Wh_Log(L"SSR: native hover tick failed");
        }
        return 0;
    }
    return DefSubclassProc(hwnd, message, wp, lp);
}
void SaveEventToken(FrameworkElement const& owner, wchar_t const* key, winrt::event_token token) {
    owner.Resources().Insert(winrt::box_value(key), winrt::box_value(token.value));
}
bool TakeEventToken(FrameworkElement const& owner, wchar_t const* key, winrt::event_token& token) {
    auto name = winrt::box_value(key);
    if (!owner.Resources().HasKey(name)) return false;
    token.value = winrt::unbox_value<int64_t>(owner.Resources().Lookup(name));
    owner.Resources().Remove(name);
    return true;
}
FrameworkElement FlyoutHoverTarget(Grid const& root) {
    auto parent = VisualTreeHelper::GetParent(root);
    for (int depth = 0; parent && depth < 12; ++depth) {
        if (auto presenter = parent.try_as<FlyoutPresenter>()) return presenter;
        parent = VisualTreeHelper::GetParent(parent);
    }
    return root;
}
void DetachFlyoutHover(Flyout const& flyout) {
    auto root = flyout.Content().try_as<Grid>();
    if (!root) return;
    auto target = FlyoutHoverTarget(root);
    winrt::event_token token{};
    if (TakeEventToken(root, L"SSRHoverOpened", token)) flyout.Opened(token);
    if (TakeEventToken(root, L"SSRHoverClosed", token)) flyout.Closed(token);
    if (TakeEventToken(root, L"SSRHoverClosing", token)) flyout.Closing(token);
    if (TakeEventToken(target, L"SSRHoverEntered", token)) target.PointerEntered(token);
    if (TakeEventToken(target, L"SSRHoverExited", token)) target.PointerExited(token);
    if (TakeEventToken(target, L"SSRHoverPressed", token)) target.PointerPressed(token);
}
void DetachPillHandlers(Border const& anchor) {
    winrt::event_token token{};
    if (TakeEventToken(anchor, L"SSRHoverTapped", token)) anchor.Tapped(token);
    if (TakeEventToken(anchor, L"SSRHoverEntered", token)) anchor.PointerEntered(token);
    if (TakeEventToken(anchor, L"SSRHoverExited", token)) anchor.PointerExited(token);
}
void BindFlyoutHover(Flyout const& flyout, HWND hwnd, unsigned resource) {
    auto opened = flyout.Opened([hwnd, resource](winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const&) {
        auto root = sender.as<Flyout>().Content().as<Grid>();
        {
            std::lock_guard<std::recursive_mutex> lock(instancesMutex);
            if (auto found = pillInstances.find(hwnd); found != pillInstances.end()) {
                auto& state = found->second->hover[resource];
                if (auto anchor = ResolveHoverAnchor(hwnd, resource)) state.overPill = CursorOverResourcePill(anchor, hwnd);
                state.Presented(GetTickCount64());
            }
        }
        auto target = FlyoutHoverTarget(root);
        auto entered = target.PointerEntered([hwnd, resource](auto const&, auto const&) {
            std::lock_guard<std::recursive_mutex> lock(instancesMutex);
            if (auto found = pillInstances.find(hwnd); found != pillInstances.end())
                found->second->hover[resource].FlyoutPointer(true, GetTickCount64());
        });
        auto exited = target.PointerExited([hwnd, resource](auto const&, auto const&) {
            std::lock_guard<std::recursive_mutex> lock(instancesMutex);
            if (auto found = pillInstances.find(hwnd); found != pillInstances.end())
                found->second->hover[resource].FlyoutPointer(false, GetTickCount64());
        });
        auto pressed = target.PointerPressed([hwnd, resource](auto const&, auto const&) {
            std::lock_guard<std::recursive_mutex> lock(instancesMutex);
            if (auto anchor = ResolveHoverAnchor(hwnd, resource)) CancelResourceHover(anchor, hwnd, resource);
        });
        SaveEventToken(target, L"SSRHoverEntered", entered);
        SaveEventToken(target, L"SSRHoverExited", exited);
        SaveEventToken(target, L"SSRHoverPressed", pressed);
    });
    SaveEventToken(flyout.Content().as<Grid>(), L"SSRHoverOpened", opened);
    auto closed = flyout.Closed([hwnd, resource](winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const&) {
        std::lock_guard<std::recursive_mutex> lock(instancesMutex);
        sender.as<Flyout>().OverlayInputPassThroughElement(nullptr);
        auto anchor = ResolveHoverAnchor(hwnd, resource);
        if (anchor && primitives::FlyoutBase::GetAttachedFlyout(anchor) == sender.as<Flyout>()) {
            if (auto found = pillInstances.find(hwnd); found != pillInstances.end()) found->second->hover[resource].Dismiss();
            StopResourceHoverTimer(anchor);
        }
    });
    SaveEventToken(flyout.Content().as<Grid>(), L"SSRHoverClosed", closed);
    auto closing = flyout.Closing([hwnd, resource](primitives::FlyoutBase const& sender, primitives::FlyoutBaseClosingEventArgs const& args) {
        std::lock_guard<std::recursive_mutex> lock(instancesMutex);
        auto found = pillInstances.find(hwnd);
        auto anchor = ResolveHoverAnchor(hwnd, resource);
        if (found == pillInstances.end() || !anchor || primitives::FlyoutBase::GetAttachedFlyout(anchor) != sender) return;
        auto& state = found->second->hover[resource];
        bool over = CursorOverResourcePill(anchor, hwnd);
        bool escape = (GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0;
        bool left = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
        bool right = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
        bool userInput = escape || left || right;
        auto now = GetTickCount64();
        if (!stopping && over && left && !right && !escape) {
            bool alreadyPinned = state.pillClickPins && now <= state.pillClickUntil &&
                state.pillClickMessage == int32_t(GetMessageTime());
            bool pin = state.hoverOpened || alreadyPinned;
            // Native light dismissal can precede Tapped. Record this click so
            // its eventual Tapped event cannot toggle the flyout a second time.
            if (!alreadyPinned) state.RememberPillClick(now, pin, int32_t(GetMessageTime()));
            if (pin) {
                state.Dismiss();
                StopResourceHoverTimer(anchor);
                args.Cancel(true);
                return;
            }
        }
        bool guard = state.GuardEarlyClose(now, over, userInput, stopping.load());
        if (guard) args.Cancel(true);
    });
    SaveEventToken(flyout.Content().as<Grid>(), L"SSRHoverClosing", closing);
}

TextBlock AddPill(StackPanel const& group, wchar_t const* label,
             wchar_t const* value, wchar_t const* glyph, double width = 65) {
    Border pill;
    pill.MinWidth(width);
    pill.Height(24);
    pill.CornerRadius({12, 12, 12, 12});
    pill.Background(SolidColorBrush(winrt::Windows::UI::Color{255, 0x21, 0x1E, 0x32}));
    pill.Margin({group.Children().Size() ? 6.0 : 0.0, 0, 0, 0});
    pill.Padding({8, 0, 8, 0});
    pill.VerticalAlignment(VerticalAlignment::Center);

    Grid layout;
    ColumnDefinition iconColumn;
    iconColumn.Width({16, GridUnitType::Pixel});
    ColumnDefinition gapColumn;
    gapColumn.Width({7, GridUnitType::Pixel});
    ColumnDefinition textColumn;
    textColumn.Width({1, GridUnitType::Star});
    layout.ColumnDefinitions().Append(iconColumn);
    layout.ColumnDefinitions().Append(gapColumn);
    layout.ColumnDefinitions().Append(textColumn);
    ColumnDefinition graphColumn;
    graphColumn.Width({1, GridUnitType::Auto});
    layout.ColumnDefinitions().Append(graphColumn);
    auto icon = MakeIcon(glyph);
    icon.VerticalAlignment(VerticalAlignment::Center);
    layout.Children().Append(icon);

    StackPanel info;
    info.VerticalAlignment(VerticalAlignment::Center);
    info.HorizontalAlignment(HorizontalAlignment::Left);
    Grid::SetColumn(info, 2);
    auto foreground = SolidColorBrush(winrt::Windows::UI::Color{255, 240, 238, 246});
    TextBlock usage;
    usage.Name(std::wstring(L"ResourcePillsValue") + label);
    usage.Text(value);
    usage.FontFamily(FontFamily(L"Segoe UI"));
    usage.FontSize(11);
    usage.FontWeight(winrt::Windows::UI::Text::FontWeight{600});
    usage.LineHeight(12);
    usage.LineStackingStrategy(LineStackingStrategy::BlockLineHeight);
    usage.Foreground(foreground);
    usage.TextWrapping(TextWrapping::NoWrap);
    TextBlock name;
    name.Text(label);
    name.Visibility(showResourceNames ? Visibility::Visible : Visibility::Collapsed);
    name.FontFamily(FontFamily(L"Segoe UI"));
    name.FontSize(9);
    name.LineHeight(10);
    name.LineStackingStrategy(LineStackingStrategy::BlockLineHeight);
    name.Foreground(foreground);
    info.Children().Append(usage);
    info.Children().Append(name);
    layout.Children().Append(info);
    Canvas graph;
    graph.Width(44);
    graph.Height(18);
    graph.Margin({8, 0, 0, 0});
    graph.VerticalAlignment(VerticalAlignment::Center);
    Grid::SetColumn(graph, 3);
    layout.Children().Append(graph);
    Canvas backgroundGraph;
    backgroundGraph.Height(18);
    backgroundGraph.VerticalAlignment(VerticalAlignment::Center);
    backgroundGraph.IsHitTestVisible(false);
    Grid::SetColumnSpan(backgroundGraph, 4);
    Canvas::SetZIndex(backgroundGraph, -1);
    layout.Children().Append(backgroundGraph);
    TextBlock identifier;
    identifier.Text(label);
    identifier.FontFamily(FontFamily(L"Segoe UI"));
    identifier.FontSize(11);
    identifier.Foreground(foreground);
    identifier.VerticalAlignment(VerticalAlignment::Center);
    identifier.TextWrapping(TextWrapping::NoWrap);
    layout.Children().Append(identifier);
    // Keep a native placement target in the visual tree for the pill's lifetime.
    // A render transform positions it without changing the pill's measured size.
    Border placement;
    placement.Name(L"SSRPlacementAnchor");
    placement.Width(1);
    placement.Height(1);
    placement.HorizontalAlignment(HorizontalAlignment::Left);
    placement.VerticalAlignment(VerticalAlignment::Top);
    placement.IsHitTestVisible(false);
    placement.Opacity(0);
    placement.RenderTransform(TranslateTransform());
    Grid::SetColumnSpan(placement, 4);
    layout.Children().Append(placement);
    layout.Background(SolidColorBrush(winrt::Windows::UI::Color{0, 0, 0, 0}));
    int flyoutResource = wcscmp(label, L"RAM") == 0 ? 1 : wcscmp(label, L"GPU") == 0 ? 2 :
        (wcscmp(label, L"Upload") == 0 || wcscmp(label, L"Download") == 0) ? 3 : 0;
    bool hasFlyout = flyoutResource != 0 || wcscmp(label, L"CPU") == 0;
    pill.IsHitTestVisible(hasFlyout);
    if (hasFlyout) {
        HWND hwnd = activeInstance->hwnd;
        pill.Resources().Insert(winrt::box_value(L"SSRHoverWindow"), winrt::box_value(uint64_t(reinterpret_cast<uintptr_t>(hwnd))));
        pill.Resources().Insert(winrt::box_value(L"SSRHoverResource"), winrt::box_value(unsigned(flyoutResource)));
        auto tappedToken = pill.Tapped([hwnd, flyoutResource](winrt::Windows::Foundation::IInspectable const& sender, input::TappedRoutedEventArgs const& args) {
            try { HandleResourceTap(sender.as<Border>(), hwnd, flyoutResource); args.Handled(true); }
            catch (winrt::hresult_error const& e) { Wh_Log(L"RP: Resource flyout failed 0x%08X", unsigned(e.code().value)); }
        });
        auto enteredToken = pill.PointerEntered([hwnd, flyoutResource](winrt::Windows::Foundation::IInspectable const& sender, input::PointerRoutedEventArgs const&) {
            try { StartResourceHover(sender.as<Border>(), hwnd, flyoutResource); }
            catch (winrt::hresult_error const& e) { Wh_Log(L"RP: Resource hover flyout failed 0x%08X", unsigned(e.code().value)); }
        });
        auto exitedToken = pill.PointerExited([hwnd, flyoutResource](winrt::Windows::Foundation::IInspectable const& sender, input::PointerRoutedEventArgs const&) {
            LeaveResourceHover(sender.as<Border>(), hwnd, flyoutResource);
        });
        SaveEventToken(pill, L"SSRHoverTapped", tappedToken);
        SaveEventToken(pill, L"SSRHoverEntered", enteredToken);
        SaveEventToken(pill, L"SSRHoverExited", exitedToken);
    }
    pill.Child(layout);
    group.Children().Append(pill);
    return usage;
}

// Keep the same controls alive across settings saves. Collapsed children do not
// occupy space; margins follow visible order so hiding the first pill leaves no gap.
void ApplyPillVisibility(StackPanel const& group, bool force = false) {
    auto a = GetAppearance();
    auto fit = ResolveTaskbarFit();
    double autoHeight = a.height == 0 ? fit.height : -1;
    if (!force && activeInstance->appliedRevision == a.revision &&
        std::abs(activeInstance->appliedAutoHeight - autoHeight) < 0.1) return;
    FontFamily font(a.font);
    bool twoRows = showResourceNames && resourceIdentifier != ResourceIdentifier::Name;
    TextBlock heightProbe;
    heightProbe.FontFamily(font);
    heightProbe.FontSize(a.valueSize);
    heightProbe.FontWeight(winrt::Windows::UI::Text::FontWeight{static_cast<uint16_t>(a.valueWeight)});
    heightProbe.Text(L"100%");
    heightProbe.Measure({10000, 10000});
    double contentHeight = twoRows ? a.valueSize + a.nameSize + 2 : double(heightProbe.DesiredSize().Height);
    if (resourceIdentifier == ResourceIdentifier::Name) {
        heightProbe.FontSize(a.identifierSize);
        heightProbe.FontWeight(winrt::Windows::UI::Text::FontWeight{400});
        heightProbe.Text(L"Download");
        heightProbe.Measure({10000, 10000});
        contentHeight = std::max(contentHeight, double(heightProbe.DesiredSize().Height));
    }
    if (resourceIdentifier == ResourceIdentifier::Icon) contentHeight = std::max(contentHeight, a.iconSize);
    double requestedHeight = a.height == 0 ? std::max(1.0, fit.height - a.margin.Top - a.margin.Bottom) : a.height;
    double height = std::max(requestedHeight, std::ceil(contentHeight + a.padding.Top + a.padding.Bottom + 2 * a.border));
    double radius = std::min(a.radius, height / 2);
    double graphHeight = std::min(a.graphHeight, std::max(4.0, height - a.padding.Top - a.padding.Bottom - 2 * a.border));
    CornerRadius corners{radius, radius, radius, radius};
    bool enabled[] = {showCpu.load(), showRam.load(), showGpu.load(),
                      showNetwork.load(), showNetwork.load()};
    bool grouped = groupedLayout.load();
    Brush background{nullptr};
    if (a.solidBackground && a.backgroundOpacity > 0) {
        SolidColorBrush brush(a.background);
        brush.Opacity(a.backgroundOpacity);
        background = brush;
    }
    SolidColorBrush borderBrush(a.borderColor);
    borderBrush.Opacity(a.borderOpacity);
    auto surface = activeInstance->surface.get();
    if (surface) {
        surface.Background(grouped ? background : nullptr);
        surface.CornerRadius(corners);
        surface.Margin(a.margin);
        double border = grouped ? a.border : 0;
        surface.BorderThickness({border, border, border, border});
        surface.BorderBrush(borderBrush);
    }
    bool first = true;
    for (uint32_t i = 0; i < group.Children().Size(); ++i) {
        auto pill = group.Children().GetAt(i).as<Border>();
        pill.Height(height - (grouped ? 2 * a.border : 0));
        pill.Padding(a.padding);
        pill.CornerRadius(corners);
        double border = grouped ? 0 : a.border;
        pill.BorderThickness({border, border, border, border});
        pill.BorderBrush(borderBrush);
        auto grid = pill.Child().as<Grid>();
        auto info = grid.Children().GetAt(1).as<StackPanel>();
        auto name = info.Children().GetAt(1).as<TextBlock>();
        auto identifierMode = resourceIdentifier.load();
        auto icon = grid.Children().GetAt(0).as<FontIcon>();
        icon.FontSize(a.iconSize);
        icon.Width(a.iconSize);
        icon.Height(a.iconSize);
        icon.Foreground(SolidColorBrush(a.identifierColor));
        auto identifier = grid.Children().GetAt(4).as<TextBlock>();
        identifier.FontFamily(font);
        identifier.FontSize(a.identifierSize);
        identifier.Foreground(SolidColorBrush(a.identifierColor));
        name.FontFamily(font);
        name.FontSize(a.nameSize);
        name.LineHeight(a.nameSize + 1);
        name.Foreground(SolidColorBrush(a.nameColor));
        auto iconVisibility = identifierMode == ResourceIdentifier::Icon ? Visibility::Visible : Visibility::Collapsed;
        auto identifierVisibility = identifierMode == ResourceIdentifier::Name ? Visibility::Visible : Visibility::Collapsed;
        if (icon.Visibility() != iconVisibility) icon.Visibility(iconVisibility);
        if (identifier.Visibility() != identifierVisibility) identifier.Visibility(identifierVisibility);
        GridLength identifierWidth = identifierMode == ResourceIdentifier::Name ? GridLength{1, GridUnitType::Auto} :
            GridLength{identifierMode == ResourceIdentifier::Icon ? a.iconSize : 0.0, GridUnitType::Pixel};
        auto column = grid.ColumnDefinitions().GetAt(0);
        auto oldWidth = column.Width();
        if (oldWidth.Value != identifierWidth.Value || oldWidth.GridUnitType != identifierWidth.GridUnitType)
            column.Width(identifierWidth);
        double gap = identifierMode == ResourceIdentifier::None ? 0 : a.identifierGap;
        auto gapColumn = grid.ColumnDefinitions().GetAt(1);
        if (gapColumn.Width().Value != gap) gapColumn.Width({gap, GridUnitType::Pixel});
        auto nameVisibility = showResourceNames && identifierMode != ResourceIdentifier::Name ? Visibility::Visible : Visibility::Collapsed;
        if (name.Visibility() != nameVisibility) name.Visibility(nameVisibility);
        // Compact line heights follow the configured sizes for two rows.
        // With one row, use natural font metrics just like the identifier.
        // Equal line boxes centre the text baseline consistently with the icon.
        auto usage = info.Children().GetAt(0).as<TextBlock>();
        usage.FontFamily(font);
        usage.FontSize(a.valueSize);
        usage.FontWeight(winrt::Windows::UI::Text::FontWeight{static_cast<uint16_t>(a.valueWeight)});
        usage.Foreground(SolidColorBrush(a.valueColor));
        TextBlock measure;
        measure.FontFamily(font);
        measure.FontSize(a.valueSize);
        measure.FontWeight(usage.FontWeight());
        double reserved = 0;
        auto reserve = [&](std::wstring const& text) {
            measure.Text(text);
            measure.Measure({10000, 10000});
            reserved = std::max(reserved, double(measure.DesiredSize().Width));
        };
        if (i < 3) {
            reserve(L"100%");
            for (wchar_t digit = L'0'; digit <= L'9'; ++digit) reserve(std::wstring(2, digit) + L"%");
        } else {
            auto units = networkBits ? std::vector<std::wstring>{L"bps", L"Kbps", L"Mbps", L"Gbps", L"Tbps"} :
                                       std::vector<std::wstring>{L"B/s", L"KB/s", L"MB/s", L"GB/s", L"TB/s"};
            for (auto const& unit : units) for (wchar_t digit = L'0'; digit <= L'9'; ++digit) {
                reserve(std::wstring(3, digit) + L" " + unit);
                reserve(std::wstring(2, digit) + L"." + digit + L" " + unit);
            }
        }
        usage.MinWidth(std::ceil(reserved));
        double lineHeight = twoRows ? a.valueSize + 1 : 0.0;
        auto strategy = twoRows ? LineStackingStrategy::BlockLineHeight : LineStackingStrategy::MaxHeight;
        if (usage.LineHeight() != lineHeight) usage.LineHeight(lineHeight);
        if (usage.LineStackingStrategy() != strategy) usage.LineStackingStrategy(strategy);
        double minimum = i < 3 ? resourceMinWidth.load() : networkMinWidth.load();
        // Minimum refers to the text/icon block. Graph space is additional.
        auto style = StyleFor(i);
        double totalMinimum = minimum + (style == GraphStyle::Boxed ? a.graphWidth + a.graphGap : 0);
        if (pill.MinWidth() != totalMinimum) pill.MinWidth(totalMinimum);
        auto graph = pill.Child().as<Grid>().Children().GetAt(2).as<Canvas>();
        graph.Width(a.graphWidth);
        graph.Height(graphHeight);
        graph.Margin({a.graphGap, 0, 0, 0});
        auto graphVisibility = style == GraphStyle::Boxed ? Visibility::Visible : Visibility::Collapsed;
        if (graph.Visibility() != graphVisibility) graph.Visibility(graphVisibility);
        auto backgroundGraph = pill.Child().as<Grid>().Children().GetAt(3).as<Canvas>();
        backgroundGraph.Height(graphHeight);
        auto backgroundVisibility = style == GraphStyle::Background ? Visibility::Visible : Visibility::Collapsed;
        if (backgroundGraph.Visibility() != backgroundVisibility) backgroundGraph.Visibility(backgroundVisibility);
        pill.Background(grouped ? nullptr : background);
        if (!enabled[i]) CloseResourceFlyout(pill);
        auto visibility = enabled[i] ? Visibility::Visible : Visibility::Collapsed;
        if (pill.Visibility() != visibility) pill.Visibility(visibility);
        double left = enabled[i] && !first && !grouped ? a.pillSpacing : 0.0;
        if (pill.Margin().Left != left) pill.Margin({left, 0, 0, 0});
        if (enabled[i]) first = false;
    }
    activeInstance->appliedRevision = a.revision;
    activeInstance->appliedAutoHeight = autoHeight;
}

bool InsertPills() {
    if (stopping) return false;
    int position = EffectivePosition(activeInstance->hwnd);
    if (position == -2) { RemovePills(); activeInstance->position = position; return true; }
    if (activeInstance->position != position) RemovePills();
    activeInstance->position = position;
    // Hold strong references only for this operation, on the owning UI thread.
    // Recover native controls whenever any weak projection has expired.
    AttachedPills attached{activeInstance->parent.get(), activeInstance->host.get(),
                           activeInstance->surface.get(), activeInstance->group.get()};
    if (!attached.parent || !attached.host || !attached.surface || !attached.group) {
        attached = FindAttachedPills(TaskbarRoot(activeInstance->hwnd));
        if (attached) {
            RememberAttachedPills(attached);
        }
    }
    // Existing pills can be refreshed directly. Root discovery is only needed
    // for first insertion or when Explorer replaced/detached their visual tree.
    if (auto parent = activeInstance->parent.get()) {
        if (auto group = activeInstance->group.get()) {
            uint32_t index;
            auto host = activeInstance->host.get();
            if (host && parent.Children().IndexOf(host, index)) {
                if (!showCpu && !showRam && !showGpu && !showNetwork) {
                    RemovePills();
                    return true;
                }
                ApplyPillVisibility(group);
                UpdateTaskbarFit();
                UpdateOverlayPosition();
                UpdateMetrics();
                return true;
            }
        }
    }
    auto root = TaskbarRoot(activeInstance->hwnd);
    int targetSlot = 0;
    auto parent = PositionParent(root, position, targetSlot);
    if (!parent || parent.ActualWidth() <= 0) {
        if (!activeInstance->missingAnchorLogged) {
            Wh_Log(L"RP: position anchor unavailable hwnd=%p position=%d; waiting", activeInstance->hwnd, position);
            activeInstance->missingAnchorLogged = true;
        }
        return false;
    }
    activeInstance->missingAnchorLogged = false;
    RemovePills();
    attached = {};
    if (!showCpu && !showRam && !showGpu && !showNetwork) return true;
    StackPanel group;
    group.Name(L"ResourcePills");
    group.Orientation(Orientation::Horizontal);
    group.VerticalAlignment(VerticalAlignment::Center);
    group.HorizontalAlignment(HorizontalAlignment::Left);
    Border surface;
    surface.CornerRadius({12, 12, 12, 12});
    surface.Margin({4, 0, 10, 0});
    surface.VerticalAlignment(VerticalAlignment::Center);
    surface.Child(group);
    group.IsHitTestVisible(true);
    AddPill(group, L"CPU", L"--%", L"\uE9D9");
    AddPill(group, L"RAM", L"--%", L"\uE964");
    AddPill(group, L"GPU", L"--%", L"\uE950");
    AddPill(group, L"Upload", L"--", L"\uE74A", 100);
    AddPill(group, L"Download", L"--", L"\uE74B", 100);
    Viewbox host;
    host.Name(L"ResourcePillsHost");
    host.Stretch(Stretch::Uniform);
    host.StretchDirection(StretchDirection::DownOnly);
    host.HorizontalAlignment(HorizontalAlignment::Left);
    host.VerticalAlignment(VerticalAlignment::Center);
    host.Child(surface);
    host.IsHitTestVisible(true);
    activeInstance->surface = winrt::make_weak(surface);
    activeInstance->host = winrt::make_weak(host);
    ApplyPillVisibility(group, true);
    activeInstance->overlay = position >= 3;
    if (!activeInstance->overlay && !slot::AcquireAt(parent, targetSlot, kMarker, activeInstance->lease)) return false;
    activeInstance->parent = winrt::make_weak(parent);
    activeInstance->group = winrt::make_weak(group);
    try {
        bool placed = false;
        if (activeInstance->overlay) {
            auto grid = parent.as<Grid>();
            Grid::SetColumn(host, 0);
            Grid::SetColumnSpan(host, std::max(1, int(grid.ColumnDefinitions().Size())));
            Grid::SetRow(host, 0);
            Grid::SetRowSpan(host, std::max(1, int(grid.RowDefinitions().Size())));
            Canvas::SetZIndex(host, 10);
            // Hide until bounds are measured, preventing a flash at the left edge.
            host.Visibility(Visibility::Collapsed);
            parent.Children().Append(host);
            placed = true;
        } else placed = slot::PlaceChild(parent, activeInstance->lease, host);
        if (!placed) {
            RemovePills();
            return false;
        }
    } catch (...) {
        RemovePills();
        throw;
    }
    UpdateTaskbarFit();
    UpdateOverlayPosition();
    UpdateMetrics();
    return true;
}

bool ProcessTaskbar(HWND hwnd, bool remove) {
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    auto& entry = pillInstances[hwnd];
    if (!entry) { entry = std::make_unique<PillInstance>(); entry->hwnd = hwnd; }
    struct Restore {
        PillInstance* previous = activeInstance;
        ~Restore() { activeInstance = previous; }
    } restore;
    activeInstance = entry.get();
    if (remove) { RemovePills(); pillInstances.erase(hwnd); return true; }
    return InsertPills();
}

// Synchronous message dispatch keeps all XAML access on the taskbar thread.
struct UiRequest { HWND hwnd; bool remove; bool completed = false; bool result = false; };
bool OnTaskbarWindowThread(HWND hwnd, bool remove) {
    if (!hwnd) return false;
    DWORD thread = GetWindowThreadProcessId(hwnd, nullptr);
    if (thread == GetCurrentThreadId()) {
        return ProcessTaskbar(hwnd, remove);
    }
    static UINT message = RegisterWindowMessageW(L"ResourcePillsDispatch_" WH_MOD_ID);
    if (!message) return false;
    HHOOK hook = SetWindowsHookExW(WH_CALLWNDPROC,
        [](int code, WPARAM wp, LPARAM lp) -> LRESULT {
            if (code == HC_ACTION) {
                auto const& event = *reinterpret_cast<CWPSTRUCT const*>(lp);
                if (event.message == message) {
                    auto& request = *reinterpret_cast<UiRequest*>(event.lParam);
                    try {
                        request.result = ProcessTaskbar(request.hwnd, request.remove);
                    } catch (winrt::hresult_error const& e) {
                        Wh_Log(L"RP: UI operation failed 0x%08X", (unsigned)e.code().value);
                    } catch (...) { Wh_Log(L"RP: UI operation failed"); }
                    request.completed = true;
                }
            }
            return CallNextHookEx(nullptr, code, wp, lp);
        }, nullptr, thread);
    if (!hook) {
        Wh_Log(L"RP: UI hook failed error=%lu", GetLastError());
        return false;
    }
    UiRequest request{hwnd, remove};
    SendMessageW(hwnd, message, 0, reinterpret_cast<LPARAM>(&request));
    UnhookWindowsHookEx(hook);
    if (!request.completed) Wh_Log(L"RP: UI dispatch callback was not reached");
    return request.completed && request.result;
}

bool OnTaskbarThread(bool remove) {
    std::vector<HWND> windows;
    if (auto primary = TaskbarWindow()) windows.push_back(primary);
    EnumWindows([](HWND hwnd, LPARAM param) -> BOOL {
        wchar_t name[64]{};
        GetClassNameW(hwnd, name, ARRAYSIZE(name));
        DWORD pid = 0;
        GetWindowThreadProcessId(hwnd, &pid);
        if (pid == GetCurrentProcessId() && wcscmp(name, L"Shell_SecondaryTrayWnd") == 0)
            reinterpret_cast<std::vector<HWND>*>(param)->push_back(hwnd);
        return TRUE;
    }, reinterpret_cast<LPARAM>(&windows));
    if (remove) {
        std::lock_guard<std::recursive_mutex> lock(instancesMutex);
        for (auto const& [hwnd, instance] : pillInstances)
            if (IsWindow(hwnd) && std::find(windows.begin(), windows.end(), hwnd) == windows.end()) windows.push_back(hwnd);
    }
    bool primaryApplied = false;
    for (auto hwnd : windows) {
        bool ok = OnTaskbarWindowThread(hwnd, remove);
        if (hwnd == TaskbarWindow()) primaryApplied = ok;
    }
    // Destroy only plain/weak state for windows Explorer already removed.
    std::lock_guard<std::recursive_mutex> lock(instancesMutex);
    for (auto it = pillInstances.begin(); it != pillInstances.end();) {
        if (!IsWindow(it->first)) it = pillInstances.erase(it);
        else ++it;
    }
    return primaryApplied;
}

void LoadSettings();
bool ResourceSystemLightMode();
static COLORREF ResourceWindowsAccentColor();
void RefreshWindowsAppearance() {
    static bool initialized = false, lastLight = false;
    static COLORREF lastAccent = 0;
    bool light = ResourceSystemLightMode();
    COLORREF accent = ResourceWindowsAccentColor();
    bool changed = initialized && (light != lastLight || accent != lastAccent);
    initialized = true;
    lastLight = light;
    lastAccent = accent;
    if (changed) {
        LoadSettings();
    }
}

DWORD WINAPI Bootstrap(void*) {
    unsigned tick = 0;
    NetworkProbe network;
    GpuProbe gpu;
    CpuDetailsProbe cpuDetails;
    MemoryDetailsProbe memoryDetails;
    bool gpuInitialized = false;
    CpuSample previous;
    bool inserted = false;
    unsigned startupAttempts = 0;
    while (!stopping) {
        RefreshWindowsAppearance();
        if (!showCpu) previous = {};
        SampleMetrics(previous);
        ++tick;
        if (showCpu && GetTickCount64() < cpuDetailDemandUntil.load()) cpuDetails.Sample(tick);
        else cpuDetails.Reset();
        if (showRam && GetTickCount64() < memoryDetailDemandUntil.load()) memoryDetails.Sample(tick);
        if (showGpu) {
            if (!gpuInitialized) { gpu.Init(); gpuInitialized = true; }
            gpu.Sample(tick);
        }
        if (showNetwork) network.Sample(tick);
        RecordGraphSample();
        bool applied = OnTaskbarThread(false);
        if (applied) inserted = true;
        if (!inserted && startupAttempts < 60 && ++startupAttempts == 60)
            Wh_Log(L"RP: primary anchor still unavailable; continuing retries for all monitors");
        // Stay alive while all pills are off so they can be enabled without reload.
        // Event makes shutdown immediate instead of waiting for the next tick.
        DWORD waitResult = WaitForSingleObject(stopEvent, inserted || startupAttempts >= 60 ? 1000 : 500);
        if (waitResult != WAIT_TIMEOUT) {
            if (waitResult == WAIT_FAILED) Wh_Log(L"SSR: sampler wait failed error=%lu", GetLastError());
            break;
        }
    }
    return 0;
}
void WINAPI StartTaskbarHook(void* self) {
    startTaskbarOriginal(self);
    if (!stopping) {
        try { if (auto hwnd = TaskbarWindow()) OnTaskbarWindowThread(hwnd, false); }
        catch (...) { Wh_Log(L"RP: taskbar rebuild insertion failed"); }
    }
}

static bool TryParseResourceHex(const std::wstring &input, unsigned &rgb)
{
    const size_t first = input.find_first_not_of(L" \t\r\n");
    if (first == std::wstring::npos)
        return false;
    const size_t last = input.find_last_not_of(L" \t\r\n");
    const size_t start = first + (input[first] == L'#' ? 1 : 0);
    if (last + 1 - start != 6)
        return false;
    unsigned value = 0;
    for (size_t i = start; i <= last; ++i)
    {
        wchar_t c = input[i];
        unsigned digit = (c >= L'0' && c <= L'9')   ? (unsigned)(c - L'0')
                         : (c >= L'a' && c <= L'f') ? (unsigned)(c - L'a' + 10)
                         : (c >= L'A' && c <= L'F') ? (unsigned)(c - L'A' + 10)
                                                    : 16;
        if (digit > 15)
            return false;
        value = (value << 4) | digit;
    }
    rgb = value;
    return true;
}
winrt::Windows::UI::Color ResourceRgb(unsigned value) {
    return {255, BYTE(value >> 16), BYTE(value >> 8), BYTE(value)};
}
// Palette reference: supplied Mawaqit v0.8.0-dev.47 by HHeitlager (MIT), ResolvePillPaletteBase:
// https://github.com/hheitlager/windhawk-mawaqit/blob/main/src/windhawk-mawaqit.wh.cpp
// Use Mawaqit text for identifiers and values, muted for names; graphs and
// borders follow the accent. Current appearance preserves the prototype colours.
static COLORREF ResourceWindowsAccentColor()
{
    struct Candidate
    {
        PCWSTR path;
        PCWSTR name;
    };
    static const Candidate candidates[] = {
        {L"Software\\Microsoft\\Windows\\DWM", L"AccentColor"},
        {L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent", L"AccentColorMenu"},
    };
    for (const auto &candidate : candidates)
    {
        HKEY key = nullptr;
        if (RegOpenKeyExW(HKEY_CURRENT_USER, candidate.path, 0, KEY_QUERY_VALUE, &key) != ERROR_SUCCESS)
            continue;
        DWORD value = 0, type = 0, bytes = sizeof(value);
        LONG status = RegQueryValueExW(key, candidate.name, nullptr, &type, reinterpret_cast<BYTE *>(&value), &bytes);
        RegCloseKey(key);
        if (status == ERROR_SUCCESS && type == REG_DWORD && bytes == sizeof(value))
            return RGB(value & 0xFF, (value >> 8) & 0xFF, (value >> 16) & 0xFF);
    }
    return GetSysColor(COLOR_HIGHLIGHT);
}
bool ResourceSystemLightMode()
{
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0,
                      KEY_QUERY_VALUE, &key) != ERROR_SUCCESS)
        return false;
    DWORD value = 0, bytes = sizeof(value), type = 0;
    LONG result =
        RegQueryValueExW(key, L"SystemUsesLightTheme", nullptr, &type, reinterpret_cast<BYTE *>(&value), &bytes);
    RegCloseKey(key);
    return result == ERROR_SUCCESS && type == REG_DWORD && value != 0;
}
std::wstring PairedResourceTheme(std::wstring const& theme, bool light) {
    wchar_t const* pairs[][2] = {
        {L"catppuccin", L"catppuccin-latte"}, {L"emberveil", L"emberveil-daybreak"},
        {L"dracula", L"dracula-light"}, {L"nord", L"nord-light"},
        {L"gruvbox", L"gruvbox-light"}, {L"tokyo-night", L"tokyo-night-day"},
        {L"solarized-dark", L"solarized-light"},
    };
    for (auto const& pair : pairs)
        if (theme == pair[0] || theme == pair[1]) return pair[light ? 1 : 0];
    return theme;
}
void ApplyTheme(AppearanceConfig& a) {
    struct Palette { wchar_t const* id; unsigned background, text, accent, muted; };
    static constexpr Palette palettes[] = {
        {L"catppuccin", 0x211E32, 0xCDD6F4, 0xCFA1FF, 0xA6ADC8},
        {L"catppuccin-latte", 0xEFF1F5, 0x4C4F69, 0x8839EF, 0x6C6F85},
        {L"emberveil", 0x171B20, 0xF5E6C8, 0xFFBC5E, 0xD9A441},
        {L"emberveil-midnight", 0x0A0C0E, 0xF5E6C8, 0xFFBC5E, 0xB8A98A},
        {L"emberveil-daybreak", 0xFFF2D8, 0x1A1F26, 0xB87924, 0x8A642D},
        {L"emerald", 0x102B27, 0xF3E8CF, 0xD4AF70, 0xB6C9BD},
        {L"dracula", 0x282A36, 0xF8F8F2, 0xBD93F9, 0x6272A4},
        {L"dracula-light", 0xF8F7FC, 0x292537, 0x7545B5, 0x655D77},
        {L"nord", 0x2E3440, 0xECEFF4, 0x88C0D0, 0x81A1C1},
        {L"nord-light", 0xECEFF4, 0x2E3440, 0x3B668B, 0x4C566A},
        {L"gruvbox", 0x282828, 0xEBDBB2, 0xFABD2F, 0x928374},
        {L"gruvbox-light", 0xFBF1C7, 0x3C3836, 0x9D0006, 0x665C54},
        {L"tokyo-night", 0x1A1B26, 0xC0CAF5, 0x7AA2F7, 0x565F89},
        {L"tokyo-night-day", 0xE1E2E7, 0x343B58, 0x2959AA, 0x61709A},
        {L"solarized-dark", 0x002B36, 0x93A1A1, 0xB58900, 0x586E75},
        {L"solarized-light", 0xFDF6E3, 0x586E75, 0x268BD2, 0x93A1A1},
        {L"rose-pine", 0x191724, 0xE0DEF4, 0xEB6F92, 0x908CAA},
        {L"everforest", 0x2D353B, 0xD3C6AA, 0xA7C080, 0x9DA9A0},
        {L"synthwave-84", 0x0E0B1F, 0xF8F8FF, 0x00E5FF, 0xB9A6FF},
        {L"flexoki", 0xFFFCF0, 0x100F0F, 0x205EA6, 0x6F6E69},
        {L"kanagawa", 0x1F1F28, 0xDCD7BA, 0x98BB6C, 0xC8C093},
        {L"ayu", 0x0B0F14, 0xE6E1CF, 0xFFB454, 0x8A9199},
        {L"one-dark", 0x282C34, 0xABB2BF, 0x61AFEF, 0x7F848E},
    };
    auto selectedSetting = WindhawkUtils::StringSetting::make(L"Style.preset");
    std::wstring selected = selectedSetting.get();
    if (selected == L"emerald-mosque") selected = L"emerald";
    bool light = ResourceSystemLightMode();
    if (Wh_GetIntSetting(L"Style.automaticTheme")) selected = PairedResourceTheme(selected, light);
    for (auto const& p : palettes) {
        if (wcscmp(selected.c_str(), p.id) != 0) continue;
        a.background = ResourceRgb(p.background);
        a.identifierColor = a.valueColor = ResourceRgb(p.text);
        a.graphColor = a.borderColor = ResourceRgb(p.accent);
        a.nameColor = ResourceRgb(p.muted);
        break;
    }
    if (wcscmp(selected.c_str(), L"custom") == 0) {
        a.background = ResourceRgb(0x211E32);
        a.identifierColor = a.valueColor = ResourceRgb(0xF5E6C8);
        a.graphColor = a.borderColor = ResourceRgb(0xFFBC5E);
        a.nameColor = ResourceRgb(0xB8A98A);
    }
    if (wcscmp(selected.c_str(), L"system") == 0) {
        COLORREF accent = ResourceWindowsAccentColor();
        winrt::Windows::UI::Color accentColor{255, GetRValue(accent), GetGValue(accent), GetBValue(accent)};
        if (!a.solidBackground || a.backgroundOpacity == 0) {
            a.background = ResourceRgb(light ? 0xF2F2F2 : 0x292929);
            a.identifierColor = a.valueColor = ResourceRgb(light ? 0x202020 : 0xF4F4F4);
            a.nameColor = ResourceRgb(light ? 0x666666 : 0xB8B8B8);
            a.graphColor = a.borderColor = accentColor;
        } else {
            a.background = accentColor;
            a.identifierColor = a.valueColor = a.nameColor = a.graphColor = a.borderColor = ResourceRgb(0xFFFFFF);
        }
    } else if (wcscmp(selected.c_str(), L"monochrome") == 0) {
        a.background = ResourceRgb(light ? 0xF2F2F2 : 0x202020);
        a.identifierColor = a.valueColor = ResourceRgb(light ? 0x202020 : 0xF4F4F4);
        a.nameColor = ResourceRgb(light ? 0x666666 : 0xB8B8B8);
        a.graphColor = a.borderColor = ResourceRgb(light ? 0x505050 : 0xD0D0D0);
    }
    struct Override { wchar_t const* key; winrt::Windows::UI::Color* target; };
    Override overrides[] = {
        {L"Overrides.background", &a.background},
        {L"Overrides.border", &a.borderColor},
        {L"Overrides.identifier", &a.identifierColor},
        {L"Overrides.value", &a.valueColor},
        {L"Overrides.name", &a.nameColor},
        {L"Overrides.graph", &a.graphColor},
    };
    for (auto const& item : overrides) {
        auto setting = WindhawkUtils::StringSetting::make(item.key);
        std::wstring color = setting.get();
        unsigned rgb = 0;
        if (TryParseResourceHex(color, rgb)) *item.target = ResourceRgb(rgb);
    }
}

double ReadNumber(wchar_t const* key, double fallback, double low, double high) {
    auto raw = WindhawkUtils::StringSetting::make(key);
    wchar_t* end = nullptr;
    double value = wcstod(raw.get(), &end);
    if (end == raw.get() || *end || !std::isfinite(value)) value = fallback;
    return std::clamp(value, low, high);
}
Thickness ReadThickness(wchar_t const* key, Thickness fallback, double low, double high) {
    auto raw = WindhawkUtils::StringSetting::make(key);
    double l, t, r, b;
    wchar_t extra;
    if (swscanf(raw.get(), L" %lf , %lf , %lf , %lf %lc", &l, &t, &r, &b, &extra) != 4 ||
        !std::isfinite(l) || !std::isfinite(t) || !std::isfinite(r) || !std::isfinite(b)) return fallback;
    return {std::clamp(l, low, high), std::clamp(t, low, high), std::clamp(r, low, high), std::clamp(b, low, high)};
}

int ReadPosition(wchar_t const* key, bool secondary) {
    auto value = WindhawkUtils::StringSetting::make(key);
    if (secondary && wcscmp(value.get(), L"follow-main") == 0) return -1;
    if (secondary && wcscmp(value.get(), L"hidden") == 0) return -2;
    if (wcscmp(value.get(), L"before-icons") == 0) return 3;
    if (wcscmp(value.get(), L"after-icons") == 0) return 4;
    if (wcscmp(value.get(), L"center") == 0) return 5;
    if (wcscmp(value.get(), L"before-start") == 0) return 6;
    if (wcscmp(value.get(), L"before-clock") == 0) return 1;
    if (wcscmp(value.get(), L"after-clock") == 0 || wcscmp(value.get(), L"after-tray") == 0) return 2;
    return 0;
}

std::mutex settingsLoadMutex;
void LoadSettings() {
    std::lock_guard<std::mutex> lock(settingsLoadMutex);
    showPrimary = Wh_GetIntSetting(L"Layout.Monitors.showPrimary") != 0;
    showSecondary = Wh_GetIntSetting(L"Layout.Monitors.showSecondary") != 0;
    flyoutOnHover = Wh_GetIntSetting(L"Flyout.openOnHover") != 0;
    hoverDelay = std::clamp(Wh_GetIntSetting(L"Flyout.hoverDelay"), 100, 3000);
    hoverCloseDelay = std::clamp(Wh_GetIntSetting(L"Flyout.hoverCloseDelay"), 100, 3000);
    flyoutAnimations = Wh_GetIntSetting(L"Flyout.animations") != 0;
    flyoutGap = std::clamp(Wh_GetIntSetting(L"Flyout.gap"), 0, 40);
    flyoutScreenMargin = std::clamp(Wh_GetIntSetting(L"Flyout.screenEdgeMargin"), 0, 100);
    flyoutWidth = std::clamp(Wh_GetIntSetting(L"Flyout.width"), 320, 1000);
    flyoutHeight = std::clamp(Wh_GetIntSetting(L"Flyout.height"), 240, 900);
    flyoutGraphHeight = std::clamp(Wh_GetIntSetting(L"Flyout.graphHeight"), 80, 400);
    flyoutTopCount = std::clamp(Wh_GetIntSetting(L"Flyout.topCount"), 1, 10);
    centerOffset = std::clamp(Wh_GetIntSetting(L"Layout.centerOffset"), -2000, 2000);
    mainPosition = ReadPosition(L"Layout.mainPosition", false);
    secondaryPosition = ReadPosition(L"Layout.secondaryPosition", true);
    showCpu = Wh_GetIntSetting(L"Resources.showCpu") != 0;
    showRam = Wh_GetIntSetting(L"Resources.showRam") != 0;
    showGpu = Wh_GetIntSetting(L"Resources.showGpu") != 0;
    showNetwork = Wh_GetIntSetting(L"Resources.showNetwork") != 0;
    showResourceNames = Wh_GetIntSetting(L"Content.showResourceNames") != 0;
    auto identifier = WindhawkUtils::StringSetting::make(L"Content.resourceIdentifier");
    resourceIdentifier = wcscmp(identifier.get(), L"name") == 0 ? ResourceIdentifier::Name :
                         wcscmp(identifier.get(), L"none") == 0 ? ResourceIdentifier::None : ResourceIdentifier::Icon;
    auto value = WindhawkUtils::StringSetting::make(L"Content.graphStyle");
    graphStyle = wcscmp(value.get(), L"boxed") == 0 ? GraphStyle::Boxed :
                 wcscmp(value.get(), L"background") == 0 ? GraphStyle::Background : GraphStyle::None;
    auto layout = WindhawkUtils::StringSetting::make(L"Layout.layout");
    groupedLayout = wcscmp(layout.get(), L"grouped") == 0;
    resourceMinWidth = std::clamp(Wh_GetIntSetting(L"Layout.Dimensions.resourceMinWidth"), 48, 400);
    networkMinWidth = std::clamp(Wh_GetIntSetting(L"Layout.Dimensions.networkMinWidth"), 48, 400);
    auto units = WindhawkUtils::StringSetting::make(L"Resources.networkSpeedUnits");
    networkBits = wcscmp(units.get(), L"bytes") != 0;
    AppearanceConfig a;
    auto font = WindhawkUtils::StringSetting::make(L"Style.Typography.fontFamily");
    if (font.get()[0]) a.font = font.get();
    auto number = [](wchar_t const* key, int low, int high) {
        return double(std::clamp(Wh_GetIntSetting(key), low, high));
    };
    auto backgroundStyle = WindhawkUtils::StringSetting::make(L"Style.Background.style");
    a.solidBackground = wcscmp(backgroundStyle.get(), L"transparent") != 0;
    a.backgroundOpacity = number(L"Style.Background.opacity", 0, 100) / 100.0;
    a.height = number(L"Style.Shape.height", 0, 100);
    a.radius = number(L"Style.Shape.cornerRadius", 0, 100);
    a.border = Wh_GetIntSetting(L"Style.Shape.borderEnabled") ? number(L"Style.Shape.borderThickness", 0, 4) : 0;
    a.borderOpacity = number(L"Style.Shape.borderOpacity", 0, 100) / 100.0;
    a.valueSize = number(L"Style.Typography.valueSize", 6, 48);
    a.valueWeight = int(number(L"Style.Typography.valueWeight", 100, 900));
    a.nameSize = number(L"Style.Typography.nameSize", 6, 48);
    a.identifierSize = number(L"Style.Typography.identifierSize", 6, 48);
    a.iconSize = number(L"Style.Icons.iconSize", 8, 48);
    a.graphWidth = number(L"Style.Graphs.width", 16, 240);
    a.graphHeight = number(L"Style.Graphs.height", 4, 100);
    a.graphGap = number(L"Layout.Spacing.graphGap", 0, 64);
    a.stroke = ReadNumber(L"Style.Graphs.lineThickness", 1.25, 0.5, 4);
    a.fillAlpha = BYTE(std::lround(number(L"Style.Graphs.fillOpacity", 0, 100) * 255 / 100));
    a.padding = ReadThickness(L"Layout.Spacing.padding", a.padding, 0, 64);
    a.margin = ReadThickness(L"Layout.Spacing.margin", a.margin, -100, 100);
    a.identifierGap = number(L"Layout.Spacing.identifierGap", 0, 64);
    a.pillSpacing = number(L"Layout.Spacing.pillSpacing", 0, 64);
    a.backgroundLineAlpha = BYTE(std::lround(number(L"Style.Graphs.backgroundLineOpacity", 0, 100) * 255 / 100));
    ApplyTheme(a);
    AcquireSRWLockExclusive(&appearanceLock);
    a.revision = appearanceConfig.revision + 1;
    appearanceConfig = std::move(a);
    ReleaseSRWLockExclusive(&appearanceLock);
}

BOOL Wh_ModInit() {
    LoadSettings();
    stopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!stopEvent) return FALSE;
    HMODULE taskbar = LoadLibraryExW(L"taskbar.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!taskbar) { CloseHandle(stopEvent); stopEvent = nullptr; return FALSE; }
    WindhawkUtils::SYMBOL_HOOK hooks[] = {
        {{LR"(const CTaskBand::`vftable'{for `ITaskListWndSite'})"}, &siteVtable},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CTaskBand::GetTaskbarHost(void)const )"}, &getHost},
        {{LR"(public: int __cdecl TaskbarHost::FrameHeight(void)const )"}, &frameHeight},
        {{LR"(public: void __cdecl std::_Ref_count_base::_Decref(void))"}, &decref},
        {{LR"(public: virtual void __cdecl TrayUI::StartTaskbar(void))"}, &startTaskbarOriginal, StartTaskbarHook},
    };
    WindhawkUtils::SYMBOL_HOOK secondaryHooks[] = {
        {{LR"(const CSecondaryTaskBand::`vftable'{for `ITaskListWndSite'})"}, &secondarySiteVtable, nullptr, true},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CSecondaryTaskBand::GetTaskbarHost(void)const )"}, &secondaryGetHost, nullptr, true},
    };
    WindhawkUtils::HookSymbols(taskbar, secondaryHooks, ARRAYSIZE(secondaryHooks));
    if (!secondarySiteVtable || !secondaryGetHost)
        Wh_Log(L"RP: secondary symbols unavailable; primary taskbar remains supported");
    bool ok = WindhawkUtils::HookSymbols(taskbar, hooks, ARRAYSIZE(hooks));
    FreeLibrary(taskbar);
    if (!ok) { CloseHandle(stopEvent); stopEvent = nullptr; return FALSE; }
    return TRUE;
}
void Wh_ModAfterInit() {
    startupWorker = CreateThread(nullptr, 0, Bootstrap, nullptr, 0, nullptr);
    if (!startupWorker) Wh_Log(L"RP: could not start sampler error=%lu", GetLastError());
}
BOOL Wh_ModSettingsChanged(BOOL* reload) {
    *reload = FALSE;
    LoadSettings();
    OnTaskbarThread(false);
    return TRUE;
}
void Wh_ModBeforeUninit() {
    stopping = true;
    if (stopEvent) SetEvent(stopEvent);
    if (startupWorker) {
        WaitForSingleObject(startupWorker, INFINITE);
        CloseHandle(startupWorker);
        startupWorker = nullptr;
    }
    if (!OnTaskbarThread(true))
        Wh_Log(L"RP: cleanup could not reach taskbar; restart Explorer if pills remain");
}
void Wh_ModUninit() {
    if (stopEvent) { CloseHandle(stopEvent); stopEvent = nullptr; }
}
