[@bs.module "react-native"] external view: ReasonReact.reactClass = "Picker";

module Item = {
  [@bs.scope "Picker"] [@bs.module "react-native"]
  external item: ReasonReact.reactClass = "Item";
  let make = (~color=?, ~label, ~value=?, ~testID=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props={
        "label": label,
        "value": value,
        "color": color,
        "testID": testID,
      },
    );
};

let encodeMode = x =>
  switch (x) {
  | `dialog => "dialog"
  | `dropdown => "dropdown"
  };

let make =
    (
      ~onValueChange=?,
      ~selectedValue=?,
      ~enabled=?,
      ~mode=?,
      ~prompt=?,
      ~itemStyle=?,
      /* view props */
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~style=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        {
          "enabled": enabled,
          "onValueChange": onValueChange,
          "selectedValue": selectedValue,
          "itemStyle": itemStyle,
          "prompt": prompt,
          "mode": UtilsRN.option_map(encodeMode, mode),
        },
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
