  <?php

/**
 * @file
 * Contains the current user argument default plugin.
 */

/**
 * Default argument plugin to extract the global $user
 *
 * This plugin actually has no options so it does not need to do a great deal.
 */
class rolereference_views_plugin_argument_default_current_user extends views_plugin_argument_default {

  /**
   * Required definition for default argument
   */
  function get_argument() {
    global $user;
    $rids = array_keys($user->roles);
    return implode("+", $rids);
  }

}
