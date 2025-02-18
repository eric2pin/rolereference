<?php
/**
 * @file
 * Interface between rolereference.module and views.module.
 */

/**
 * Implements hook_views_plugins().
 *
 * Defines some plugins used by the Views modes for
 * rolereference.
 */
function rolereference_views_plugins() {
  $plugins = array(
    //'module' => 'rolereference', // This just tells our themes are elsewhere.
    'display' => array(
      'rolereference_views_plugin_display' => array(
        'path' => backdrop_get_path('module', 'rolereference') . '/includes',
        'title' => 'Role reference',
        'help' => 'Destination-agnostic display. Mostly useful for programmatic views.',
        'handler' => 'rolereference_views_plugin_display.inc',
        'no ui' => TRUE, // Programmatic use only.
        'uses hook menu' => FALSE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
      ),
    ),
    'style' => array(
      'rolereference_views_plugin_style' => array(
        'path' => backdrop_get_path('module', 'rolereference') . '/includes',
        'title' => 'Results array (with title)',
        'help' => 'Returns the view as a PHP array of names + rendered rows.',
        'handler' => 'rolereference_views_plugin_style.inc',
        'no ui' => TRUE, // Programmatic use only.
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
        'even empty' => TRUE,
      ),
    ),
    'argument default' => array(
      'rolereference_current_roles' => array(
        'title' => t('User Roles IDs from logged in user'),
        'path' => backdrop_get_path('module', 'rolereference') . '/includes',
        'handler' => 'rolereference_views_plugin_argument_default_current_user.inc',
      ),
    ),
  );
  return $plugins;
}
