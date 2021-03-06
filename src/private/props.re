let serialize = (handlers: option(Types.touchResponderHandlers)) =>
  switch (handlers) {
  | None => Js.Obj.empty()
  | Some(handlers) =>
    Types.{
      "onMoveShouldSetResponder":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onMoveShouldSetResponder,
        ),
      "onMoveShouldSetResponderCapture":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onMoveShouldSetResponderCapture,
        ),
      "onResponderGrant": handlers.onResponderGrant,
      "onResponderMove": handlers.onResponderMove,
      "onResponderReject": handlers.onResponderReject,
      "onResponderRelease": handlers.onResponderRelease,
      "onResponderTerminate": handlers.onResponderTerminate,
      "onResponderTerminationRequest": handlers.onResponderTerminationRequest,
      "onStartShouldSetResponder":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onStartShouldSetResponder,
        ),
      "onStartShouldSetResponderCapture":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onStartShouldSetResponderCapture,
        ),
    }
  };

let extendView =
    (
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
      moreProps,
    ) =>
  UtilsRN.objAssign2(
    {
      "accessibilityLabel": accessibilityLabel,
      "accessible": accessible,
      "hitSlop": hitSlop,
      "onAccessibilityTap": onAccessibilityTap,
      "onLayout": onLayout,
      "onMagicTap": onMagicTap,
      "removeClippedSubviews": removeClippedSubviews,
      "pointerEvents":
        Belt.Option.map(pointerEvents, Types.pointerEventsToJs),
      "style": style,
      "testID": testID,
      "accessibilityComponentType":
        Belt.Option.map(
          accessibilityComponentType,
          Types.accessibilityComponentTypeToJs,
        ),
      "accessibilityLiveRegion":
        Belt.Option.map(
          accessibilityLiveRegion,
          Types.accessibilityLiveRegionToJs,
        ),
      "collapsable": collapsable,
      "importantForAccessibility":
        Belt.Option.map(
          importantForAccessibility,
          Types.importantForAccessibilityToJs,
        ),
      "needsOffscreenAlphaCompositing": needsOffscreenAlphaCompositing,
      "renderToHardwareTextureAndroid": renderToHardwareTextureAndroid,
      "accessibilityTraits":
        Belt.Option.map(accessibilityTraits, x =>
          x |> List.map(Types.accessibilityTraitToJs) |> Array.of_list
        ),
      "accessibilityViewIsModal": accessibilityViewIsModal,
      "shouldRasterizeIOS": shouldRasterizeIOS,
    },
    moreProps,
    serialize(responderHandlers),
  );
