<?php

/**
 * @file
 * Common file.
 */

/**
 * Checks the existence of the log.
 *
 * @param int $node
 *   Parameter node view.
 * @param int $uid
 *   Parameter $user->uid.
 *
 * @return bool
 *   Isset.
 */
function node_log_is_logged($node, $uid) {

  $latency = variable_get('node_log_latency');
  $time = REQUEST_TIME - $latency;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node_log_entity');
  $query->propertyCondition('nid', $node->nid);
  $query->propertyCondition('uid', $uid);
  $query->propertyCondition('timestamp', $time, '>');
  $query->propertyOrderBy('aid', 'DESC');
  $query->range(0, 1);
  $checkEntity = $query->execute();

  return isset($checkEntity['node_log_entity']);
}
