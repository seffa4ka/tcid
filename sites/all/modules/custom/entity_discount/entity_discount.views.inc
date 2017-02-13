<?php

/**
 * @file
 * Entity discount views file.
 */

/**
 * Implements hook_views_data_alter().
 */
function entity_discount_views_data_alter(&$data) {
  $data['entity_discount_discount']['username'] = array(
    'title' => t('User name'),
    'help' => t('No.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'relationship field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('code'),
    ),
  );
}
